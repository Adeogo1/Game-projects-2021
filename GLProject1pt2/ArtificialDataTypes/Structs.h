//
// Created by a016817k on 25/05/2021.
//

#ifndef SUMMER_GAME_PROJECTS_STRUCTS_H
#define SUMMER_GAME_PROJECTS_STRUCTS_H
#include <iostream>
#include <math.h>
#include <tuple>
#include "../Initializations/HelloGL.h"
using namespace std;


struct Color{
    GLfloat r,g,b;
};

struct Rect2D{
    float x,y;
    float width, height;
    Rect2D(float x_pos = 0, float y_pos = 0, float width = 0, float height = 0){
        x= x_pos;
        y = y_pos;
        this->width = width;
        this->height = height;
    }
};

struct Vector2{
    float x, y;

    Vector2(float x = 0, float y = 0){
        this->x=x;
        this->y = y;
    };
    float CalculateDistance(Vector2 v1, Vector2 v2) {
        float a = v1.x - v2.x;
        float b = v1.y - v2.y;
        return sqrt((pow(a,2) +pow(b,2)));
    }
    /*tuple<Vector2,Vector2>CalcCoordsFromDistH(float distance, Vector2 starttingCoords){

    }*/
    Vector2 CalcCoordsFromDistH(float distance, Vector2 startingCoords){
      Vector2 finalCoords;
      finalCoords.y = startingCoords.y;
      finalCoords.x = distance + (-startingCoords.y);
        return finalCoords;
    }
    Vector2 CalcCoordsFromDistV(float distance, Vector2 startingCoords){
      Vector2 finalCoords;
      finalCoords.x = startingCoords.x;
      finalCoords.y = distance + (-startingCoords.x);
        return finalCoords;
    }
};



#endif //SUMMER_GAME_PROJECTS_STRUCTS_H
