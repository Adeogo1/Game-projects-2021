#include "Physics.h"

void Physics::Particle::FixedUpdate(float _fixedDeltaTime)
{
	m_Position += m_Velocity * _fixedDeltaTime + m_Acceleration * _fixedDeltaTime * _fixedDeltaTime * 0.5f;
}
