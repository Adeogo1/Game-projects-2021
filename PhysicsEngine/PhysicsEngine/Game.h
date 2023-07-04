#pragma once
#include <iostream>
#include <SDL.h>
using namespace std;

class Game
{
public:
	Game();
	~Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

private:

	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	SDL_Window* m_Window;
	bool m_IsRunning;

};



