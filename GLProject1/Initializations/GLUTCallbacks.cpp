//
// Created by a016817k on 22/05/2021.
//

#include "GLUTCallbacks.h"
#include "HelloGL.h"
#include "../ArtificialDataTypes/Constants.h"

namespace GLUTCallbacks{
    namespace {
        //initialize to null pointer before we do anything
        HelloGL* helloGL = nullptr;
    }
    void Init(HelloGL* gl){
        helloGL = gl;
    }
    void Display(){
        if(helloGL != nullptr)
        {

            helloGL->Display();
        }
    }
    void Timer(int preferredRefresh){
        int updateTime = glutGet(GLUT_ELAPSED_TIME);
            helloGL->Update();
            updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
        glutTimerFunc(REFERESHRATE - updateTime,GLUTCallbacks::Timer,REFERESHRATE);
    }

    void Keyboard(unsigned char key, int x, int y) {
        helloGL->Keyboard(key,x,y);
    }

    void KeyboardUp(unsigned char key, int x, int y) {
        helloGL->KeyboardUp(key,x,y);
    }

    void Special(int key, int x, int y) {
        helloGL->Special(key,x,y);
    }

    void SpecialUp(int key, int x, int y) {
        helloGL->SpecialUp(key,x,y);
    }

    void Mouse(int button, int state, int x, int y) {
        helloGL->Mouse(button,state,x,y);
    }

    void Motion(int x, int y) {
        helloGL->Motion(x,y);
    }

    void PassiveMotion(int x, int y) {
        helloGL->PassiveMotion(x,y);
    }


}