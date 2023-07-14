#pragma once
#include "RepeatedIncludes.h"
#include "Maths.h"
using namespace Maths;

class Component
{
public:
	Component(class Actor* _owner, int updateOrder = 10);

	virtual void Update(float _deltaTime);

	virtual void ProcessInput(const uint8_t* _keyState){}

	int GetUpdateOrder() const { return m_UpdateOrder; }



	virtual ~Component();

protected:
	class Actor* m_Owner;

	int m_UpdateOrder;

};

