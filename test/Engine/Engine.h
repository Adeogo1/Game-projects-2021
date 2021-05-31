//
// Created by a016817k on 30/05/2021.
//

#ifndef TEST_ENGINE_H
#define TEST_ENGINE_H
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
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

    SDL_Renderer *GetMRenderer() const {
        return m_renderer;
    }

private:
    Engine();
    static Engine* s_Instance;
    SDL_Window* m_Window;
    SDL_Renderer* m_renderer;
    bool m_IsRunning;

};
//    delete s_Instance;
//    delete m_Window;
//    delete m_renderer;

#endif //TEST_ENGINE_H
