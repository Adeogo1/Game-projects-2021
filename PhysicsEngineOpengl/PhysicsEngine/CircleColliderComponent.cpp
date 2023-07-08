#include "CircleColliderComponent.h"



CircleColliderComponent::CircleColliderComponent(Actor* _owner) : Component(_owner)
{
}

float CircleColliderComponent::GetRadius() const
{
	return m_Radius;
}

const Vector2& CircleColliderComponent::GetCenter() const
{
	return m_Owner->m_Transform->GetPosition();
}

bool Intersect(const CircleColliderComponent& a, const CircleColliderComponent& b)
{
	Vector2 diff = a.GetCenter() - b.GetCenter();
	float distSq = diff.LengthSq();

	float radiiSq = a.GetRadius() + b.GetRadius();
	radiiSq *= radiiSq;

	return distSq <= radiiSq;
}

CircleColliderComponent::~CircleColliderComponent()
{
}



