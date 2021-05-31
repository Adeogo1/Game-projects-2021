//
// Created by a016817k on 30/05/2021.
//

#include "InputManager.h"

InputManager* InputManager::s_Instance = nullptr;

void InputManager::Listen() {
    SDL_Event e;
    while (SDL_PollEvent(&e)){
        switch (e.type) {
            case SDL_QUIT:
                Engine::GetInstance()->Quit();
                break;
            case SDL_KEYDOWN:
                KeyDown();
                break;
            case SDL_KEYUP:
                KeyUp();
                break;
            default:
                break;
        }
    }
}

bool InputManager::GetKeyDown(SDL_Scancode key) {
    return (m_KeyStates[key] == 1);
}

void InputManager::KeyUp() {
    m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void InputManager::KeyDown() {
    m_KeyStates = SDL_GetKeyboardState(nullptr);
}
