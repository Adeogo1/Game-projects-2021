//
// Created by a016817k on 30/05/2021.
//

#include "Engine.h"

Engine* Engine::s_Instance = nullptr;

Engine::Engine() {

}

bool Engine::Init(char* name) {
    if ((SDL_Init(SDL_INIT_VIDEO) != 0 ) )
    {
        SDL_Log("failed to initialise SDL: %s", SDL_GetError());
        return false;
    }

    m_Window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_OPENGL);
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
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);


    m_PaddlePos = {10.0f,768/2.0f };
    m_BallPos = {1024/2.0f,768/2.0f};
    m_BallVel = {-200.0f, 235.0f};
    x = y =0;
    x = static_cast<int>(m_BallPos.X - 15);
    y = static_cast<int>(m_BallPos.Y - 15);

    return m_IsRunning = true;
}

bool Engine::Clean() {
    //clean everything
    SDL_DestroyWindow(m_Window);
    SDL_DestroyRenderer(m_renderer);
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
    SDL_SetRenderDrawColor(m_renderer,0, 0, 255, 255);
    SDL_RenderClear(m_renderer);





    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_Rect wall =  {0,0,1024,15};//top wall
    SDL_RenderFillRect(m_renderer,&wall);

    wall = {0,768 - 15,1024,15};//bottom wall
    SDL_RenderFillRect(m_renderer, &wall);
    wall = {1024-15, 0, 15, 1024};//right wall
    SDL_RenderFillRect(m_renderer, &wall);
    wall = {0, 0, 15, 1024};
    SDL_RenderFillRect(m_renderer, &wall);
    ball = {x,y, 15,15};

    SDL_RenderPresent(m_renderer);
}

void Engine::Events() {
    InputManager::GetInstance()->Listen();
}

Engine::~Engine() {

}

SDL_Texture *Engine::LoadTexture(const char *fileName) {
    SDL_Surface* surf = IMG_Load(fileName);
    if(!surf){
        SDL_Log("failed to load texture from file %s", fileName);
        return nullptr;
    }
    SDL_Texture* text = SDL_CreateTextureFromSurface(m_renderer,surf);
    SDL_FreeSurface(surf);
    if (!text){
        SDL_Log("failed to convert surface to texture for %s", fileName);
        return nullptr;
    }
    return text;
}

