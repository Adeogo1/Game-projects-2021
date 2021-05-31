//
// Created by a016817k on 30/05/2021.
//

#ifndef GLSDLPROJECT1PT2_ENGINE_H
#define GLSDLPROJECT1PT2_ENGINE_H
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <SDL2/SDL_image.h>
#include "../DataTypes/Constants.h"
#include "../DataTypes/Structs.h"
#include "../InputManager/InputManager.h"
#include "Timer.h"
using namespace std;

class Engine {
public:
    static Engine* GetInstance(){

        return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
    }

    bool Init(char* name);
    bool Clean();
    void Quit();

    void Update();
    void Render();
    void Events();
    virtual ~Engine();

    inline bool IsRunning(){
        return m_IsRunning;
    }


    SDL_Texture* LoadTexture(const char* fileName);

private:
    Engine();
    static Engine* s_Instance;
    SDL_Window* m_Window;
    bool m_IsRunning;

    int m_PaddleDir;
    Vector2 m_PaddlePos;
    Vector2 m_BallPos;
    Vector2 m_BallVel;
    int x, y;

    SDL_Rect ball;

};
//    delete s_Instance;
//    delete m_Window;
//    delete m_renderer;

#endif //GLSDLPROJECT1PT2_ENGINE_H
