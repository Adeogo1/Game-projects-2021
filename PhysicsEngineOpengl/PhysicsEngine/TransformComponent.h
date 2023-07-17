#pragma once
#include "Component.h"


 class TransformComponent:public Component
{
public:
	TransformComponent(class Actor* _owner);

	void Update(float _deltaTime) override;

	void ComputeWorldTransform();
	void OnUpdateWorldTransform() override;

	//Vector3 GetForward() const {
	//	return Vector3(cos(m_Rotation), 0.0f, sin(m_Rotation));
	//}

	inline Vector3 GetScale() const {
		return m_Scale;
	}
	

	inline void SetPosition(Vector3 _pos) {
		m_Position = _pos;
	}	

	inline Vector3 GetPosition() const {
		return m_Position;
	}
		

	inline Vector3 GetRotation() const {
		return m_Rotation;
	}

	inline Matrix4 GetWorldTransform() {
		return m_WorldTransform;
	}

	//inline void SetRotation(float _rotation) {
	//	m_Rotation = _rotation;
	//}

private:
	Matrix4 m_WorldTransform;
	Vector3 m_Scale;
	Vector3 m_Position;
	Vector3 m_Rotation;
	bool m_RecomputeWorldTransform;
};

