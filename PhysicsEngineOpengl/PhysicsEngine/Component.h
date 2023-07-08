#pragma once
#include "RepeatedIncludes.h"
#include "Maths.h"
using namespace Maths;

class Component
{
public:
	Component(class Actor* _owner, int updateOrder = 10);

	virtual void Update(float _deltaTime);

	int GetUpdateOrder() const { return m_UpdateOrder; }

	~Component();

protected:
	class Actor* m_Owner;

	int m_UpdateOrder;

};

