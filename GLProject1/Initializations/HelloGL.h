//
// Created by a016817k on 22/05/2021.
//

#ifndef UNTITLED_HELLOGL_H
#define UNTITLED_HELLOGL_H
#include <Windows.h>
#include <GL/glut.h>
#include "GL\freeglut.h"
#include <gl/gl.h>
#include <gl/glut.h>
#include <gl/glu.h>
#include "GLUTCallbacks.h"
#include "../Draw2DShapes/Draw2D.h"
#include "../ArtificialDataTypes/Constants.h"
#include "../ArtificialDataTypes/Structs.h"
#include "../ArtificialDataTypes/Camera.h"
#include <iostream>

class HelloGL {
private:
    Draw2D* shapes;
    Camera* camera;
    float m_rotation;
    float LR,UD,FD;
    Rect2D square;
public:
    HelloGL(int argc, char* argv[]);
    void Display();
    void Update();

    //Input
    void Keyboard(unsigned char key, int x, int y);
    void KeyboardUp(unsigned char key, int x, int y);
    void Special(int key, int x, int y);//for keys like the function key e.g GLUT_KEY_F1
    void SpecialUp(int key, int x, int y);
    void Mouse(int button, int state, int x, int y);
    void Motion(int x, int y);//when the mouse moves when the button is pressed
    void PassiveMotion(int x, int y);
    //https://www.opengl.org//resources/libraries/glut/spec3/node45.html there's more and how to use the ones above

    //UI
    void DrawString(const char* text, Vector3* pos, Color* color);

    ~HelloGL();
};


#endif //UNTITLED_HELLOGL_H
