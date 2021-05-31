//
// Created by a016817k on 30/05/2021.
//

#ifndef GLSDLPROJECT1PT2_INPUTMANAGER_H
#define GLSDLPROJECT1PT2_INPUTMANAGER_H
#include <SDL.h>
#include "../Engine/Engine.h"



class InputManager {
public:
    static InputManager* GetInstance(){ return s_Instance = (s_Instance != nullptr) ? s_Instance : new InputManager();}
    void Listen();// looks/waits for the event
    bool GetKeyDown(SDL_Scancode key);
    void KeyUp();
private:
    InputManager(){m_KeyStates = SDL_GetKeyboardState(nullptr);}
    void KeyDown();

    const Uint8* m_KeyStates;

    static InputManager* s_Instance;
};


#endif //GLSDLPROJECT1PT2_INPUTMANAGER_H
