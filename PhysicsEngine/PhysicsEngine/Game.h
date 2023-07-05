#pragma once
#include <iostream>
#include <map>
#include <SDL.h>
#include "Maths.h"
using namespace std;
using namespace Maths;




 const int THICKNESS = 15;
 const float paddleH = 100.0f;


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
	bool GetAxis(char _axis);
	bool GetAxisRaw( char _axis);
	void UpdateGame();
	void GenerateOutput();
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	bool m_IsRunning;
	Vector2 m_PaddlePos = Vector2();
	Vector2 m_BallPos = Vector2();
	Vector2 m_BallVel;
	Uint32 m_TicksCount;
	int m_PaddleDir;
	

};



