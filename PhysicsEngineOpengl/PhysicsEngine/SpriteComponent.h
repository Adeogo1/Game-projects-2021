#pragma once
#include "Actor.h"
#include "Shader.h"

class SpriteComponent : public Component
{
public:
	SpriteComponent(class Actor* _owner, int _updateOrder, int _drawOrder = 100);
	virtual void Draw(Shader* shader);
	virtual void SetTexture(class Texture* _texture);

	int GetDrawOrder() const { return m_DrawOrder; }
	int GetTexWidth() const { return m_TexHeight; }
	int GetTexHeight() const { return m_TexHeight; }

	~SpriteComponent();

protected:
	class Texture* m_Texture;
	int m_DrawOrder;
	int m_TexWidth;
	int m_TexHeight;

};




