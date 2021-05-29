//
// Created by a016817k on 27/05/2021.
//

#ifndef SUMMER_GAME_PROJECTS_CAMERA_H
#define SUMMER_GAME_PROJECTS_CAMERA_H
#include "Vector3.h"

class Camera{
public:
    Vector3 eye, center, up;
    Camera(Vector3 eye = {0,0,0}, Vector3 center= {0,0,0}, Vector3 up= {0,0,0}) {
        this->eye = eye;
        this->center = center;
        this->up = up;
    }
    ~Camera(){}

};


#endif //SUMMER_GAME_PROJECTS_CAMERA_H
