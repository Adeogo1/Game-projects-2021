#pragma once
#include "Actor.h"
class Ship : public Actor
{
public:
	Ship(class Game* game, Actor* _parent, string _name, bool _static = false);

	void UpdateActor(float deltaTime) override;
	void ActorInput(const uint8_t* keyState) override;
private:
	float mLaserCooldown;
};
