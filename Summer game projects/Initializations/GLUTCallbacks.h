//
// Created by a016817k on 22/05/2021.
//
#ifndef UNTITLED_GLUTCALLBACKS_H
#define UNTITLED_GLUTCALLBACKS_H
class HelloGL;

namespace GLUTCallbacks{
    void Init(HelloGL* gl);

    void Display();

    void Timer(int preferredRefresh);

    //Input
    void Keyboard(unsigned char key, int x, int y);
    void KeyboardUp(unsigned char key, int x, int y);
    void Special(int key, int x, int y);//for keys like the function key e.g GLUT_KEY_F1
    void SpecialUp(int key, int x, int y);
    void Mouse(int button, int state, int x, int y);
    void Motion(int x, int y);
    void PassiveMotion(int x, int y);
}


#endif //UNTITLED_GLUTCALLBACKS_H
