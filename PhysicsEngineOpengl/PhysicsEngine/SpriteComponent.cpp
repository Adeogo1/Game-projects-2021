#include "SpriteComponent.h"



SpriteComponent::SpriteComponent()
{
}

void SpriteComponent::Draw(Shader* shader)
{
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

}

SpriteComponent::~SpriteComponent()
{
}

