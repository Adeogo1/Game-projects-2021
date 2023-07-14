#include "Ship.h"
#include "Game.h"
#include "SpriteComponent.h"

Ship::Ship(Game* game, Actor* _parent, string _name, bool _static) :Actor(game, nullptr, "ship")
	, mLaserCooldown(0.0f)
{
	// Create a sprite component
	SpriteComponent* sc = new SpriteComponent(this, 150,3);
}

void Ship::UpdateActor(float deltaTime)
{
}

void Ship::ActorInput(const uint8_t* keyState)
{
}
