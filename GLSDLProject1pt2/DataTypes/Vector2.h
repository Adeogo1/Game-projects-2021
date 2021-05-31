//
// Created by a016817k on 27/05/2021.
//

#ifndef GLSDLPROJECT1PT2_VECTOR2_H
#define GLSDLPROJECT1PT2_VECTOR2_H

class Vector2{
public:
    float X,Y;


public:
    Vector2(float x= 0, float y=0):X(x), Y(y){}
    ~Vector2(){}
    inline Vector2 operator+(const Vector2& v2) const{
        return Vector2(X + v2.X, Y +v2.Y);
    }
    inline Vector2 operator-(const Vector2& v2) const{
        return Vector2(X - v2.X, Y - v2.Y);
    }
    inline Vector2 operator*(const float scalar) const{
        return Vector2(X * scalar, Y * scalar);
    }

};



#endif //GLSDLPROJECT1PT2_VECTOR3_H
