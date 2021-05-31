//
// Created by a016817k on 30/05/2021.
//

#ifndef TEST_TIMER_H
#define TEST_TIMER_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

const int TARGET_FPS = 60;
const float TARGET_DELTATIME = 1.5f;

class Timer {
public:
    void Tick();
    inline float GetDeltaTime() const {return m_DeltaTime;}
    static Timer* GetInstance() {return s_Instance = (s_Instance != nullptr) ? s_Instance : new Timer();}
    void Clean();
    ~Timer();
private:
    Timer();
    static Timer* s_Instance;
    float m_DeltaTime;
    float m_LastTime;
};


#endif //TEST_TIMER_H
