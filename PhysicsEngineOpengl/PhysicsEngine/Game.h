#pragma once

#include "RepeatedIncludes.h"
#include <SDL_image.h>
#include "Maths.h"
#include "Actor.h"
using namespace Maths;




 const int THICKNESS = 15;
 const float paddleH = 100.0f;



 const float Vertices2D[][6] = {
	 { -0.5f, 0.5f, 0.0f},
	 {0.5f, 0.5f, 0.0f},
	 {0.5f, -0.5f, 0.0f },
	 {0.5f, -0.5f, 0.0f},
	 { -0.5f, -0.5f, 0.0f},
	 { -0.5f, 0.5f, 0.0f}
 };


 static int CreateShader(const string& _vertexShader, const string& _fragmentShader) {

 }

class Game
{
public:
	
	Game();
	~Game();
	bool Initialize();
	bool LoadShaders();
	void RunLoop();
	void Shutdown();
	void InitSpriteVerts();
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

	class VertexArray* m_SpriteVerts;

	class Shader* m_SpriteShader;
	//vector <class Sp
	

};



