#pragma once
#include "Component.h"


 class TransformComponent:public Component
{
public:
	TransformComponent(class Actor* _owner, int updateOrder = 10);

	void Update(float _deltaTime) override;

	Vector2 GetForward() const {
		return Vector2(cos(m_Rotation), -sin(m_Rotation));
	}

	inline Vector2 GetScale() const {
		return m_Scale;
	}
	

	inline Vector2 GetPosition() const {
		return m_Position;
	}
		

	inline float GetRotation() const {
		return m_Rotation;
	}

	~TransformComponent();


private:
	Vector2 m_Scale;
	Vector2 m_Position;
	float m_Rotation;
};

