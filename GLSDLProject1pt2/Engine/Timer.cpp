//
// Created by a016817k on 30/05/2021.
//

#include "Timer.h"

Timer * Timer::s_Instance = nullptr;

void Timer::Tick() {
    m_LastTime = 0.0f;
    m_DeltaTime = 0.0f;
}

Timer::Timer() {
    m_DeltaTime = (SDL_GetTicks() - m_LastTime) * (TARGET_FPS / 1000.0f);
    if (m_DeltaTime > TARGET_DELTATIME){
        m_DeltaTime = 1.5f;
    }
    m_LastTime = SDL_GetTicks();
}

void Timer::Clean() {
    delete s_Instance;
    s_Instance = nullptr;
}

Timer::~Timer() {
    Clean();
}
