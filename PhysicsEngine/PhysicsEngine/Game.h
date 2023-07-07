#pragma once
#include "RepeatedIncludes.h"
#include <SDL.h>
#include "Maths.h"
#include "Actor.h"
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
	void AddActor(Actor* _actor);
	void RemoveActor(Actor* _actor);

private:

	vector<Actor*> m_Actors;
	vector<Actor*> m_PendingActors;
	bool m_UpdatingActor;

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



