#include "Actor.h"


Actor::Actor(Game* _game, Actor* _parent, string _name, bool _static)
{
	m_Transform = new TransformComponent(_parent);
	m_Components.push_back(m_Transform);
}

Actor::~Actor()
{
}

void Actor::Update(float _deltaTime)
{
	if (m_ActorState != State::EActive)return;
	UpdateComponent(_deltaTime);
	UpdateActor(_deltaTime);
}

void Actor::UpdateComponent(float _deltaTime)
{
	for (Component* c : m_Components)
	{
		c->Update(_deltaTime);
	}
}

void Actor::UpdateActor(float _deltaTime)
{

}

void Actor::Draw()
{
}

void Actor::AddComponent(Component* comp)
{
}

void Actor::RemoveComponent(Component* comp)
{
}
