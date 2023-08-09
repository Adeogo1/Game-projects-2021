#include "Game.h"
#include "VertexArray.h"
#include "Shader.h"
#include "SpriteComponent.h"
#include "Ship.h"
#include "Texture.h"





Game::Game()
{
	m_Window = nullptr;
	m_IsRunning = true;
	m_UpdatingActor = false;
	m_TicksCount = 0;
	m_Context = nullptr;
	m_SpriteShader = nullptr;
}

Game::~Game()
{
}

bool Game::Initialize()
{
	int sdlResults = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResults != 0)
	{
		//puts(SDL_GetError());
		SDL_Log("Unable to initialise SDL: %s", SDL_GetError());
		return false;
	}
	//Use the core opengl profile
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	//specify version 3.3
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	//request a colour buffer with 8-bits per RGBA channel
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	

	//Enable double buffering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//force OpenGl to use hardware acceleration
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	m_Window = SDL_CreateWindow("Physics Engine", 
		100, // Top left x-coordinate of window
		100, // Top left y-coordinate of window
		1024, // Width of window
		768, // Height of window
		SDL_WINDOW_OPENGL // Flags (0 for no flags set)
		);

	if (!m_Window)
	{
		SDL_Log("Failed to Create window: %s", SDL_GetError());
		return false;
	}

	m_Context = SDL_GL_CreateContext(m_Window);
	if (!m_Context) {
		SDL_Log("Context Error:  %s", SDL_GetError());
		return false;
	}

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		SDL_Log("Failed to initialize GLEW");
		return false;
	}
	// GLEW will emit a benign error code,
	glGetError();

	if (!LoadShaders())
	{
		SDL_Log("Failed to load shaders.");
		return false;
	}
	InitSpriteVerts();

	m_Ship = new Ship(this,nullptr, "ship");

	m_TicksCount = SDL_GetTicks();
	
	m_Shot = new Particle();

	switch (m_CurrentShotType)
	{
	case PISTOL:
		m_Shot->SetMass(2.0f);
		m_Shot->SetVelocity(Vector3(0.0f, 0.0f, 35.0f));
		m_Shot->SetAcceleration(Vector3(0.0f, -1.0f, 0.0f));
		m_Shot->SetDamping(0.99f);
		break;
	default:
		break;
	}

	return true;
}

bool Game::LoadShaders()
{
	m_SpriteShader = new Shader();
	if (!m_SpriteShader->Load("Shaders/Sprite.vert", "Shaders/Sprite.frag"))
	{
		return false;
	}
m_SpriteShader->SetActive();
	Matrix4 viewProj = Matrix4::CreateSimpleViewProj(1024.f, 768.f);
	m_SpriteShader->SetMatrixUniform("u_ViewProj", viewProj);
	
	return true;
}

void Game::UnloadData()
{
	//delete actor
	// because ~actor calls RemoveActor
	while (!m_Actors.empty())
	{
		delete m_Actors.back();
	}

	//Destroy Texture
	for (auto i : m_Textures)
	{
		i.second->Unload();
		delete i.second;
	}
	m_Textures.clear();

}

void Game::RunLoop()
{
	while (m_IsRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::Shutdown()
{

	UnloadData();
	delete m_SpriteVerts;
	m_SpriteShader->Unload();
	delete m_SpriteShader;

	SDL_GL_DeleteContext(m_Context);

	SDL_DestroyWindow(m_Window);

	SDL_Quit();
}

void Game::InitSpriteVerts()
{
	float vertices[] = {
		-0.5f,  0.5f, 0.f, 0.f, 0.f, // top left
		 0.5f,  0.5f, 0.f, 1.f, 0.f, // top right
		 0.5f, -0.5f, 0.f, 1.f, 1.f, // bottom right
		-0.5f, -0.5f, 0.f, 0.f, 1.f  // bottom left
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	m_SpriteVerts = new VertexArray(vertices, 4, indices, 6);
}

void Game::AddActor(Actor* _actor)
{
	if (m_UpdatingActor)
	{
		m_PendingActors.emplace_back(_actor);
	}
	else
	{
		m_Actors.emplace_back(_actor);
	}
}

void Game::RemoveActor(Actor* _actor)
{
	auto iter = find(m_PendingActors.begin(), m_PendingActors.end(), _actor);
	if (iter != m_PendingActors.end())
	{
		iter_swap(iter, m_PendingActors.end() - 1);
		m_PendingActors.pop_back();
	}

	iter = find(m_Actors.begin(), m_Actors.end(), _actor);
	if (iter != m_Actors.end())
	{
		iter_swap(iter, m_Actors.end() - 1);
		m_Actors.pop_back();
	}
}

Texture* Game::GetTexture(const string& _fileName)
{
	Texture* tex = nullptr;
	auto iter = m_Textures.find(_fileName);
	if (iter != m_Textures.end())
	{
		tex = iter->second;
	}
	else
	{
		tex = new Texture();
		if (tex->Load(_fileName))
		{
			m_Textures.emplace(_fileName, tex);
		}
		else
		{
			delete tex;
			tex = nullptr;
		}
	}
	return tex;
}

void Game::AddSprite(SpriteComponent* sprite)
{
	// Find the insertion point in the sorted vector
	// (The first element with a higher draw order than me)
	int myDrawOrder = sprite->GetDrawOrder();
	auto iter = m_Sprites.begin();
	for (;
		iter != m_Sprites.end();
		++iter)
	{
		if (myDrawOrder < (*iter)->GetDrawOrder())
		{
			break;
		}
	}
	// Inserts element before position of iterator
	m_Sprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
	auto iter = std::find(m_Sprites.begin(), m_Sprites.end(), sprite);
	m_Sprites.erase(iter);
}


void Game::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_IsRunning = false;
			break;
		default:
			break;
		}
	}

	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_ESCAPE])
	{
		m_IsRunning = false;
	}

	m_UpdatingActor = true;
	for (auto actors: m_Actors)
	{
		actors->ProcessInput(state);
	}
	m_UpdatingActor = false;
}

//bool Game::GetAxis( char _axis)
//{
//	_axis = toupper(_axis);
//
//	switch (_axis)
//	{
//	default:
//		break;
//	}
//}
//
//bool Game::GetAxisRaw( char _axis)
//{
//}

void Game::UpdateGame()
{
#pragma region DeltaTime
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), m_TicksCount + 16));
	//delta time is the difference in ticks from last frame converted to seconds
	float deltaTime = (SDL_GetTicks() - m_TicksCount) / 1000.0f;
	m_TicksCount = SDL_GetTicks();
	deltaTime = Clamp(deltaTime, deltaTime,  0.05f);
#pragma endregion

	m_UpdatingActor = true;
	for (auto actor : m_Actors)
	{
		actor->Update(deltaTime);
	}
	m_UpdatingActor = false;

	for (auto pending : m_PendingActors)
	{
		pending->UpdateComponent(deltaTime);
		m_Actors.emplace_back(pending);
	}
	m_PendingActors.clear();

	vector<Actor*> deadActor;
	for (auto actor : m_Actors)
	{
		if (actor->GetState() == Actor::EDead)
		{
			deadActor.emplace_back(actor);
		}
	}

	for (auto actors : deadActor)
	{
		delete actors;
	}

	//SDL_Log("deltaTime %f", deltaTime);
}

void Game::FixedUpdateGame()
{
}

void Game::GenerateOutput()
{
	glClearColor(0.86f, 0.86f, 0.86f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(
		GL_SRC_ALPHA, // srcFactor is srcAlpha
		GL_ONE_MINUS_SRC_ALPHA // dstFactor is 1 - srcAlpha
	);

	//set sprite shader and vertex array objects active
	m_SpriteShader->SetActive();
	m_SpriteVerts->SetActive();

	//draw all sprites
	for (auto sprite : m_Sprites)
	{
		sprite->Draw(m_SpriteShader);
	}


	//swap buffers, which also displays the scene

	SDL_GL_SwapWindow(m_Window);

}

