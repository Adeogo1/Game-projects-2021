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
	
	class Texture* GetTexture(const string& _fileName);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

private:

	vector<Actor*> m_Actors;
	vector<Actor*> m_PendingActors;
	bool m_UpdatingActor;

	vector<class SpriteComponent*> m_Sprites;
	unordered_map<string, class Texture*> m_Textures;

	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void InitSpriteVerts();
	bool LoadShaders();
	void UnloadData();


	SDL_Window* m_Window;
	bool m_IsRunning;
	Uint32 m_TicksCount;
	SDL_GLContext m_Context;

	class VertexArray* m_SpriteVerts;
	class Ship* m_Ship;

	class Shader* m_SpriteShader;
	//vector <class SpriteC
	
};



