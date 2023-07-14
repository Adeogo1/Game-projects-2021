#pragma once
#include "Actor.h"
#include "Shader.h"

class SpriteComponent : public Component
{
public:
	SpriteComponent(class Actor* _owner, int _drawOrder , int _updateOrder);
	virtual void Draw(Shader* shader);

	int GetDrawOrder() const { return m_DrawOrder; }
	int GetTexWidth() const { return m_TexHeight; }
	int GetTexHeight() const { return m_TexHeight; }

	~SpriteComponent();

private:
	int m_DrawOrder;
	int m_TexWidth;
	int m_TexHeight;

};




