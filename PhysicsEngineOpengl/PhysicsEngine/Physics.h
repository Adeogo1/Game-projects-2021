#pragma once
#include "RepeatedIncludes.h"
#include "Maths.h"
#include <assert.h>
using namespace Maths;

namespace Physics {

	/// <summary>
	/// Aparticle is the simplest object that can be simulated in the physics system
	/// </summary>
	class Particle
	{
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
		void SetMass(const float _mass) {
			assert(_mass != 0);
			m_InverseMass = (float)1.0f / _mass;
		}

		float GetMass() {
			if (m_InverseMass == 0)
			{
				return INT_MAX;
			}
			else
			{
				return ((float)1.0f) / m_InverseMass;
			}
		}
		
		void SetInverseMass(const float _inverseMass) {
			
			m_InverseMass = _inverseMass;
		}		
		float GetInverseMass() {
			
			return m_InverseMass;
		}

	public:
		void FixedUpdate(float _fixedDeltaTime);

	protected:

		//holds the inverse of the mass of the particle. 
		//it is more useful to hold the inverse mass because 
		//intergration is simpler and because in real time
		// simulation it is more useful to have objects with infinite mass (immovable) 
		//than 0 mass (completely unstable in numerical simulation )
		float m_InverseMass;
	};




};
