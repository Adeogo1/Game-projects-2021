//
// Created by a016817k on 27/05/2021.
//

#ifndef SUMMER_GAME_PROJECTS_VECTOR3_H
#define SUMMER_GAME_PROJECTS_VECTOR3_H

class Vector3{
public:
    float X,Y,Z;


public:
    Vector3(float x= 0, float y=0, float z=0):X(x), Y(y), Z(z){}
    ~Vector3(){}
    inline Vector3 operator+(const Vector3& v2) const{
        return Vector3(X + v2.X, Y +v2.Y, Z + v2.Z);
    }
    inline Vector3 operator-(const Vector3& v2) const{
        return Vector3(X - v2.X, Y - v2.Y, Z - v2.Z);
    }
    inline Vector3 operator*(const float scalar) const{
        return Vector3(X * scalar, Y * scalar, Z * scalar);
    }

};



#endif //SUMMER_GAME_PROJECTS_VECTOR3_H
