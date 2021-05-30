//
// Created by a016817k on 30/05/2021.
//

#include "Engine.h"

Engine* Engine::s_Instance = nullptr;

Engine::Engine() {

}

bool Engine::Init(char* name) {
    if ((SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0))
    {
        SDL_Log("failed to initialise SDL: %s", SDL_GetError());
        return false;
    }
    m_Window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENWIDTH, SCREENHEIGHT, 0);
    if (m_Window == nullptr)// if the window wasnt initialised
    {
        SDL_Log("failed to Create Window: %s", SDL_GetError());
        return false;
    }
    m_renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);// the 3rd parameter is how the renderer should work, should it be synchronized with the frequence of our system or not. - the values in the third parameter means that we are snchronising it with the frame rate of our screen
    if (m_renderer == nullptr)
    {
        SDL_Log("failed to Create Renderer: %s", SDL_GetError());
        return false;
    }

    return m_IsRunning = true;
}

bool Engine::Clean() {
    //clean everything
    SDL_DestroyWindow(m_Window);
    SDL_DestroyRenderer(m_renderer);
    //IMG_Quit();
    SDL_Quit();
    Timer::GetInstance()->Clean();
    return true;
}

void Engine::Quit() {
m_IsRunning = false;
}

void Engine::Update() {
    Uint32 newTime = SDL_GetTicks();
    float deltaTime = Timer::GetInstance()->GetDeltaTime();
}

void Engine::Render() {
    SDL_SetRenderDrawColor(m_renderer,67, 0, 111, 255);
    SDL_RenderClear(m_renderer);

    SDL_RenderPresent(m_renderer);
}

void Engine::Events() {

}

Engine::~Engine() {

}
