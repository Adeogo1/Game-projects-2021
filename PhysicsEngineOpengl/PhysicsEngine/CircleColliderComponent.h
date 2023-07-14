#pragma once
#include "Actor.h"


class CircleColliderComponent : public Component
{
public:
	CircleColliderComponent(Actor* _owner, int _updateOrder);

	void SetRadius(float _radius) { m_Radius = _radius; }

	float GetRadius() const;

	/*const Vector2& GetCenter() const;*/

	

	~CircleColliderComponent();

private:
	float m_Radius;

};
//bool Intersect(const CircleColliderComponent& a, const CircleColliderComponent& b);