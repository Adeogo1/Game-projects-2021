#include "Physics.h"

void Physics::Particle::SetMass(const float _mass)
{
	
	assert(_mass != 0);
	m_InverseMass = (float)1.0f / _mass;
	
}

float Physics::Particle::GetMass()
{
	if (m_InverseMass == 0)
	{
		return INT_MAX;
	}
	else
	{
		return ((float)1.0f) / m_InverseMass;
	}
}

void Physics::Particle::SetInverseMass(const float _inverseMass)
{
	m_InverseMass = _inverseMass;
}

float Physics::Particle::GetInverseMass()
{
	return m_InverseMass;
}

bool Physics::Particle::HasFiniteMass() const
{
	return m_InverseMass >= 0.0f;
}

void Physics::Particle::SetDamping(const float _damping)
{
	m_Damping = _damping;
}

float Physics::Particle::GetDamping() const
{
	return m_Damping;
}

void Physics::Particle::SetPosition(const Vector3& _position)
{
	m_Position = _position;
}

Vector3 Physics::Particle::GetPosition() const
{
	return m_Position;
}

void Physics::Particle::SetVelocity(const Vector3& _velocity)
{
	m_Velocity = _velocity;
}

Vector3 Physics::Particle::GetVelocity() const
{
	return m_Velocity;
}

void Physics::Particle::SetAcceleration(const Vector3& _acceleration)
{
	m_Acceleration = _acceleration;
}

void Physics::Particle::ClearAccumulator()
{
	m_ForceAccum.Clear();
}

void Physics::Particle::FixedUpdate(float _fixedDeltaTime)
{
	m_Position += m_Velocity * _fixedDeltaTime + m_Acceleration * _fixedDeltaTime * _fixedDeltaTime * 0.5f;
}

void Physics::Particle::Intergrate(float _duration)
{
	assert(_duration > 0.0f);

	//update linear position 
	m_Position += m_Velocity * _duration;

	//work out the acceleration of the force
	Vector3 resultingAcc = m_Acceleration;
	resultingAcc += m_ForceAccum * m_InverseMass;

	//update linear velocity from the acceleration
	m_Velocity += resultingAcc * _duration;

	m_Velocity *= powf(m_Damping, _duration);

	ClearAccumulator();

}

void Physics::Particle::AddForce(const Vector3& _force)
{
	m_ForceAccum += _force;
}
