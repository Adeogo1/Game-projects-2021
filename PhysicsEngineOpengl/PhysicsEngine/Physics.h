#pragma once
#include "RepeatedIncludes.h"
#include "Maths.h"
#include <assert.h>
using namespace Maths;

namespace Physics {

	/// <summary>
	/// Aparticle is the simplest object that can be simulated in the physics system
	/// Characteristics are properties of the particle
	/// independent of its current kinematic situation.This
	///	includes mass, moment of inertiaand damping
	///	properties.Two identical particles will have the same
	//	values for their characteristics.
	/// </summary>
	class Particle
	{
		/*
		 * State includes all the characteristics and also includes
         * the kinematic situation of the particle in the current
         * simulation. By setting the whole state data, a particle's
         * exact game state can be replicated. Note that state does
         * not include any forces applied to the body. Two identical
         * rigid bodies in the same simulation will not share the same
         * state values.
		 * The state values make up the smallest set of independent
         * data for the particle. Other state data is calculated
         * from their current values. When state data is changed the
         * dependent values need to be updated: this can be achieved
         * either by integrating the simulation, or by calling the
         * calculateInternals function. This two stage process is used
         * because recalculating internals can be a costly process:
         * all state changes should be carried out at the same time,
         * allowing for a single call.
		*/
	public:
		//holds the linear position of a particle in world space 
		Vector3 m_Position;

		//holds the linear velocity of the particle in world space
		Vector3 m_Velocity;

		//holds the acceleration of the particle. This value can be used to set acceleration due to gravity 
		//(its primary use ) or any other constant acceleration
		Vector3 m_Acceleration;
		
		/**
* Holds the amount of damping applied to linear
* motion. Damping is required to remove energy added
* through numerical instability in the integrator.
*/
float m_Damping;


/**
 * Holds the accumulated force to be applied at the next
 * simulation iteration only. This value is zeroed at each
 * integration step.
 */
Vector3 m_ForceAccum;


		/*
		 * These functions are used to simulate the particle's
		 * motion over time. A normal application sets up one or more
		 * rigid bodies, applies permanent forces (i.e. gravity), then
		 * adds transient forces each frame, and integrates, prior to
		 * rendering.
		 *
		 * Currently the only integration function provided is the
		 * first order Newton Euler method.
		 */

void SetMass(const float _mass);

float GetMass();

void SetInverseMass(const float _inverseMass);

float GetInverseMass();

bool HasFiniteMass() const;

void SetDamping(const float _damping);

float GetDamping() const;

void SetPosition(const Vector3& _position);

Vector3 GetPosition() const;

void SetVelocity(const Vector3& _velocity);

Vector3 GetVelocity()const;

void SetAcceleration(const Vector3& _acceleration);

/**
		 * Clears the forces applied to the particle. This will be
		 * called automatically after each integration step.
		 */
void ClearAccumulator();

	public:
		void FixedUpdate(float _fixedDeltaTime);

		/// <summary>
		/// Intergrates the particle forward in time by the given amount.
		/// This function uses Newton Euler Intergration method, which is ia linear approximaition
		/// for this reason it may be inaccurate in some cases
		/// </summary>
		/// <param name="_duration"></param>
		void Intergrate(float _duration);


		void AddForce(const Vector3& _force);

	protected:

		//holds the inverse of the mass of the particle. 
		//it is more useful to hold the inverse mass because 
		//intergration is simpler and because in real time
		// simulation it is more useful to have objects with infinite mass (immovable) 
		//than 0 mass (completely unstable in numerical simulation )
		float m_InverseMass;
	};




};
