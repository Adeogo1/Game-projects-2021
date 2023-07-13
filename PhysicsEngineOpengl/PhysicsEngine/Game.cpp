#include "Game.h"
#include "VertexArray.h"






Game::Game()
{
	m_Window = nullptr;
	m_IsRunning = true;
	m_UpdatingActor = false;
	m_TicksCount = 0;
	m_Context = nullptr;
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


	Vector2 test(5, 5);
	test = test * 5.0f;
	test.Print();
	//test *= 2.5f;
	//test.Print();
	//test *= Vector2(3.25f, 8.0f);
	//test.Print();
	test = Vector2(1, 5) * test;
	test.Print();



	
	return true;
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

	while (!m_Actors.empty())
	{
		delete m_Actors.back();
	}

	IMG_Quit();

	SDL_GL_DeleteContext(m_Context);

	SDL_DestroyWindow(m_Window);

	SDL_Quit();
}

void Game::InitSpriteVerts()
{
	m_SpriteVerts = new VertexArray(Vertices, 4, indexBuffer, 6);
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

void Game::GenerateOutput()
{
	glClearColor(0.86f, 0.86f, 0.86f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT);
	//TODO: Draw Scene

	//swap buffers, which also displays the scene

	SDL_GL_SwapWindow(m_Window);

}

