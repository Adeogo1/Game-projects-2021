#include "Component.h"
#include "Actor.h"


Component::Component(Actor* _owner, int updateOrder)
{
	m_Owner = _owner;
	m_UpdateOrder = updateOrder;
	m_Owner->AddComponent(this);
}

void Component::Update(float _deltaTime)
{
}

Component::~Component()
{
	m_Owner->RemoveComponent(this);
}

