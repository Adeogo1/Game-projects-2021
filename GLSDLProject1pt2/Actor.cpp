//
// Created by a016817k on 31/05/2021.
//

#include "Actor.h"

Actor::Actor() {

}

Actor::~Actor() {

}

void Actor::Update(float deltaTime) {
    UpdateComponents(deltaTime);
    UpdateActor(deltaTime);
}

void Actor::UpdateComponents(float deltaTime) {

}

void Actor::UpdateActor(float deltaTime) {

}

void Actor::Render() {

}

void Actor::AddComponent(Component *component) {

}

void Actor::RemoveComponent(Component *component) {

}
