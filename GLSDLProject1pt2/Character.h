//
// Created by a016817k on 31/05/2021.
//

#ifndef GLSDLPROJECT1PT2_CHARACTER_H
#define GLSDLPROJECT1PT2_CHARACTER_H
#include "Actor.h"

class Character : public Actor{
public:
    void Update(float deltaTime)override;
    void Render()override;

};


#endif //GLSDLPROJECT1PT2_CHARACTER_H
