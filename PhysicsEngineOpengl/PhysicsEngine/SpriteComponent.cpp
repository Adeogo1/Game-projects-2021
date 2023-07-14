#include "SpriteComponent.h"
#include "Game.h"



SpriteComponent::SpriteComponent(class Actor* _owner, int _drawOrder, int _updateOrder ) : Component(_owner, _updateOrder)
{
	m_DrawOrder = _drawOrder;
	m_Owner->GetGame()->AddSprite(this);
}

void SpriteComponent::Draw(Shader* shader)
{
	SDL_Log("erfdf");
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

}

SpriteComponent::~SpriteComponent()
{
}

