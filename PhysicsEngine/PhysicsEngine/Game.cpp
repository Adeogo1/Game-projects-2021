#include "Game.h"





Game::Game()
{
	m_Window = nullptr;
	m_IsRunning = true;
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

	SDL_DestroyWindow(m_Window);

	SDL_Quit();
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

}

void Game::UpdateGame()
{
}

void Game::GenerateOutput()
{
}
