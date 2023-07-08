#include "TransformComponent.h"

TransformComponent::TransformComponent(class Actor* _owner, int updateOrder) : Component(_owner, updateOrder)
{
}

void TransformComponent::Update(float _deltaTime)
{
}

TransformComponent::~TransformComponent()
{
}

