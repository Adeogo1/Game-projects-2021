//
// Created by a016817k on 31/05/2021.
//

#ifndef GLSDLPROJECT1PT2_GAMEOBJECT_H
#define GLSDLPROJECT1PT2_GAMEOBJECT_H
#include "/DataTypes/Structs.h"

class GameObject {
public:
    void AddComponent(Component* comp);
    void RemoveComponent(Component* comp);

private:
    unordered_set<Component*> m_Components;

};


#endif //GLSDLPROJECT1PT2_GAMEOBJECT_H
