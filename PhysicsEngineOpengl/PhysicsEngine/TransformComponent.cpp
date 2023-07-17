#include "TransformComponent.h"
#include "Actor.h"

TransformComponent::TransformComponent(class Actor* _owner) : Component(_owner)
{
	m_Owner = _owner;
	//m_UpdateOrder = updateOrder;
	m_RecomputeWorldTransform = true;
	m_WorldTransform = Matrix4::Identity;
}

void TransformComponent::Update(float _deltaTime)
{
	ComputeWorldTransform();
}

void TransformComponent::ComputeWorldTransform()
{
	if (m_RecomputeWorldTransform)
	{
		m_RecomputeWorldTransform = false;
		//scale, rotate, translate

		m_WorldTransform = Matrix4::CreateScale(m_Scale);
		m_WorldTransform *= Matrix4::CreateRotation(m_Rotation);
		m_WorldTransform *= Matrix4::CreateTranslation(m_Position);


	}
}

void TransformComponent::OnUpdateWorldTransform()
{

}






