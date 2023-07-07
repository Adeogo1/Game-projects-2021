#include "TransformComponent.h"

TransformComponent::TransformComponent(class Actor* _owner, int updateOrder = 10) : Component(_owner, updateOrder)
{
}

TransformComponent::~TransformComponent()
{
}

