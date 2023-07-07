#pragma once
#include "Component.h"


 class TransformComponent:public Component
{
public:
	TransformComponent(class Actor* _owner, int updateOrder = 10);
	~TransformComponent();
	Vector2 m_Scale;
	Vector2 m_Position;
	float m_Rotation;

private:

};

