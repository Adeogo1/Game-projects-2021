//
// Created by a016817k on 25/05/2021.
//

#ifndef SUMMER_GAME_PROJECTS_DRAW2D_H
#define SUMMER_GAME_PROJECTS_DRAW2D_H
#include <Windows.h>
#include <GL/glut.h>
#include "GL\freeglut.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include <iostream>
using namespace std;

class Draw2D {
    public:
Draw2D();

    void Isosceles();
    void Equalateral();
    void Acute();
    void RightAngle();
    void Obtuse();
    void Hexagon();
    void Pentagon();
~Draw2D();

public:
    void DrawScalene();
};

#endif //SUMMER_GAME_PROJECTS_DRAW2D_H
