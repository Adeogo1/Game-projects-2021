#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "Engine/Engine.h"
using namespace std;

int main(int argc, char* args[]) {
    char Title[] = "Adeeeehhhhhh";
    Engine::GetInstance()->Init(Title);
    while (Engine::GetInstance()->IsRunning()){
        Engine::GetInstance()->Events();
        Engine::GetInstance()->Update();
        Engine::GetInstance()->Render();
        Timer::GetInstance()->Tick();
    }
    Engine::GetInstance()->Clean();
    return 0;
}
