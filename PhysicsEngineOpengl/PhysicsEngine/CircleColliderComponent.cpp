#include "CircleColliderComponent.h"



CircleColliderComponent::CircleColliderComponent(Actor* _owner, int _updateOrder) : Component(_owner, _updateOrder)
{
	m_Radius = 0.0f;
}

float CircleColliderComponent::GetRadius() const
{
	return m_Radius;
}
//
//const Vector2& CircleColliderComponent::GetCenter() const
//{
//	//return m_Owner->m_Transform->GetPosition();
//	return .Zero();
//}

//bool Intersect(const CircleColliderComponent& a, const CircleColliderComponent& b)
//{
//	Vector2 diff = a.GetCenter() - b.GetCenter();
//	float distSq = diff.LengthSq();
//
//	float radiiSq = a.GetRadius() + b.GetRadius();
//	radiiSq *= radiiSq;
//
//	return distSq <= radiiSq;
//}

CircleColliderComponent::~CircleColliderComponent()
{
}



