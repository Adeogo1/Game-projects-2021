#include "Game.h"





Game::Game()
{
	m_Window = nullptr;
	m_Renderer = nullptr;
	m_IsRunning = true;
	m_BallPos = Vector2(1024.0f/2.0f, 768 / 2.0f);
	m_PaddlePos = Vector2(10, 768.0f/2.0f);
	m_PaddleDir = 0;
	m_BallVel = Vector2(-200.0f, 235.0f);
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

	m_Window = SDL_CreateWindow("Physics Engine", 
		100, // Top left x-coordinate of window
		100, // Top left y-coordinate of window
		1024, // Width of window
		768, // Height of window
		0 // Flags (0 for no flags set)
		);
	if (!m_Window)
	{
		SDL_Log("Failed to Create window: %s", SDL_GetError());
		return false;
	}
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!m_Renderer)
	{
		SDL_Log("Renderer Unsuccessful:  %s", SDL_GetError());
	}

	
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

	SDL_DestroyRenderer(m_Renderer);

	SDL_DestroyWindow(m_Window);

	SDL_Quit();
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
	m_PaddleDir = 0;
	if (state[SDL_SCANCODE_W])
	{
		m_PaddleDir -= 1;
	}
	if (state[SDL_SCANCODE_S])
	{
		m_PaddleDir += 1;
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

#pragma region PaddleStuff
	//m_PaddlePos.y = Clamp(m_PaddlePos.y, (paddleH) + THICKNESS, 768.0f - THICKNESS);
	//if (m_PaddleDir != 0)
	//{
	//	m_PaddlePos.y += m_PaddleDir * 300.0f * deltaTime;
	//}
	//cout << m_BallPos.y << endl;
	//
	//m_BallPos.x += m_BallVel.x * deltaTime;
	//m_BallPos.y += m_BallVel.y * deltaTime;
	//if ((m_BallPos.y <= THICKNESS)&& m_BallVel.y <0.0f)
	//{
	//	m_BallVel.y *= -1;
	//}
	//if ( m_BallPos.y >= 768 - THICKNESS && m_BallVel.y >0.0f)
	//{
	//	m_BallVel.y *= -1;
	//}
	//if ( m_BallPos.x >= 1024 - THICKNESS && m_BallVel.x >0.0f)
	//{
	//	m_BallVel.x *= -1;
	//}
	//float diff = m_BallPos.y - m_PaddlePos.y;
	//diff = (diff < 0) ? diff *= -1 : diff;

	//if (diff <= paddleH/2.0f && m_BallPos.x <=25.0f && m_BallPos.x>= 20.0f && m_BallVel.x < 0.0f)
	//{
	//	m_BallVel.x *= -1.0f;
	//}
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
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 255,255);
	SDL_RenderClear(m_Renderer);
	SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);

	//draw ceiling wall
	SDL_Rect wall{
		0,0,1024,THICKNESS
	};
	SDL_RenderFillRect(m_Renderer, &wall);
	
	//draw floor wall
	wall.y = 768 - THICKNESS;
	SDL_RenderFillRect(m_Renderer, &wall);	


	//draw right wall
	wall.x = 1024 - THICKNESS;
	wall.y = 0;
	wall.w = THICKNESS;
	wall.h = 1024;
	SDL_RenderFillRect(m_Renderer, &wall);
	
	
	//draw Paddle ball
	SDL_Rect Ball{
		static_cast<int>(m_BallPos.x - THICKNESS/2), static_cast<int>(m_BallPos.y - THICKNESS/2),THICKNESS,THICKNESS
	};
	SDL_RenderFillRect(m_Renderer, &Ball);

	//draw Paddle
	SDL_Rect Paddle{
		static_cast<int>(m_PaddlePos.x),static_cast<int>(m_PaddlePos.y - paddleH),THICKNESS,static_cast<int>(paddleH)
	};
	SDL_RenderFillRect(m_Renderer, &Paddle);

	SDL_RenderPresent(m_Renderer);
}

