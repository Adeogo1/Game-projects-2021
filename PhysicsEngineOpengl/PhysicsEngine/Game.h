#pragma once
#include <glew.h>
#include "RepeatedIncludes.h"
#include <SDL_image.h>
#include "Maths.h"
#include "Actor.h"
using namespace Maths;




 const int THICKNESS = 15;
 const float paddleH = 100.0f;

 const float Vertices[] = {
	 -0.5f, 0.5f, 0.0f, //vertex 0 
	 0.5f, 0.5f, 0.0f, //vertex 1
	 0.5f, -0.5f, 0.0f, //vertex 2
	 -0.5f, -0.5f, 0.0f,// vertex 3
 };

 unsigned short indexBuffer[] = {
	 0,1,2,
	 2,3,0
 };

 const float Vertices2D[][6] = {
	 { -0.5f, 0.5f, 0.0f},
	 {0.5f, 0.5f, 0.0f},
	 {0.5f, -0.5f, 0.0f },
	 {0.5f, -0.5f, 0.0f},
	 { -0.5f, -0.5f, 0.0f},
	 { -0.5f, 0.5f, 0.0f}
 };

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
	void UpdateGame();
	void GenerateOutput();
	SDL_Window* m_Window;
	bool m_IsRunning;
	Uint32 m_TicksCount;
	SDL_GLContext m_Context;
	

};



