//
// Created by a016817k on 31/05/2021.
//

#ifndef GLSDLPROJECT1PT2_ACTOR_H
#define GLSDLPROJECT1PT2_ACTOR_H
#include "/Engine/Engine.h"

class Actor {//base gameobject
public:

    enum State{//used to track state of the actor
        EActive,
        EPaused,
        EDead
    };

    Actor();//class Engine* engine - as a parameter but Engine is already a singleton
    virtual ~Actor();

    void Update(float deltaTime);//called from engine cpp cannot be overridden
    void UpdateComponents(float deltaTime);//update all the component attached to the actor
    virtual void UpdateActor(float deltaTime);// - any actor specific code

    virtual void Render();//Draw

    void AddComponent(Component* component);
    void RemoveComponent(Component* component);

private:
    State m_State;
    Vector2 m_Position;
    float m_Scale;
    float m_Rotation;//rotation angle in radians
    vector<Component*> m_Components;

};


#endif //GLSDLPROJECT1PT2_ACTOR_H
