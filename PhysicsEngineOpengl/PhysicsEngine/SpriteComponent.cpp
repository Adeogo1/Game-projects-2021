#include "SpriteComponent.h"
#include "Game.h"
#include "Texture.h"



SpriteComponent::SpriteComponent(class Actor* _owner, int _updateOrder , int _drawOrder) : Component(_owner, _updateOrder)
{
	m_Texture = nullptr;
	m_TexWidth = m_TexHeight = 0;
	m_DrawOrder = _drawOrder;
	m_Owner->GetGame()->AddSprite(this);
}

void SpriteComponent::Draw(Shader* shader)
{
	if (m_Texture)
	{

		Matrix4 scaleMat = Matrix4::CreateScale(
			static_cast<float> (m_TexWidth),
			static_cast<float>(m_TexHeight),
			1.0f
		);
		Matrix4 world = scaleMat * m_Owner->GetTransform()->GetWorldTransform();
		shader->SetMatrixUniform("u_WorldTransform", world);

		m_Texture->SetActive();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}
}

void SpriteComponent::SetTexture(Texture* _texture)
{
	m_Texture = _texture;
	m_TexWidth = _texture->GetWidth();
	m_TexWidth = _texture->GetHeight();

}

SpriteComponent::~SpriteComponent()
{
	m_Owner->GetGame()->RemoveSprite(this);
}

