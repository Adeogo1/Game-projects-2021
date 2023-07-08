#pragma once
#include <math.h>
#include "RepeatedIncludes.h"




namespace Maths {
	const float Pi = 3.1415926535f;
	template <typename T>
	T Clamp(const T& _value, const T& _lower, const T& _Upper) {
		return min(_Upper, max(_lower, _value));
	}

	inline float ToDegrees(const float& _radians) {
		return (_radians * 180.0f / Pi);
	}
	
	inline float ToRadians(const float& _degrees) {
		return (_degrees * Pi/180.0f);
	}

	class Vector2
	{
	public:
		float x = 0, y = 0;
		Vector2():x(0.0f),y(0.0f) {}
		Vector2(float _x, float _y):x(_x),y(_y) {}

		void Print() {
			SDL_Log("X: %f, Y: %f", x, y);
		}

		Vector2 Zero() {
			x = 0;
			y = 0;
			return Vector2(x, y);
		}

		Vector2 Normalize() {
			Vector2 temp = Vector2(x, y);
			x = x / Length(temp);
			y = y / Length(temp);
			return *this;
		}

		~Vector2(){}

		inline Vector2& operator+= (const Vector2& _rhs) {
			x += _rhs.x;
			y += _rhs.y;
			return *this;
		}

		inline Vector2& operator* (const float& _rhs) {
			x *= _rhs;
			y *= _rhs;
			return *this;
		}

		inline Vector2& operator* (const Vector2& _rhs) {
			x *= _rhs.x;
			y *= _rhs.y;
			return *this;
		}
		
		inline Vector2& operator*=(const float& _rhs) {
			x *= _rhs;
			y *= _rhs;
			return *this;
		}
		
		
		inline Vector2& operator*=(const Vector2& _rhs) {
			x *= _rhs.x;
			y *= _rhs.y;
			return *this;
		}
		
		
		inline Vector2& operator-(const float& _rhs) {
			x -= _rhs;
			y -= _rhs;
			return *this;
		}
		
			
		
		friend Vector2 operator-(const Vector2& _lhs, const Vector2& _rhs) {
			return Vector2(_lhs.x - _rhs.x, _lhs.y - _rhs.y);
		}
		
		
		inline Vector2& operator-=(const float& _rhs) {
			x -= _rhs;
			y -= _rhs;
			return *this;
		}
		
		
		inline Vector2& operator-=(const Vector2& _rhs) {
			x -= _rhs.x;
			y -= _rhs.y;
			return *this;
		}

		static float Length(Vector2& _vec1) {
			return (sqrt(pow(_vec1.x, 2) + pow(_vec1.y, 2)));
		}

		static float LengthSq(Vector2& _vec1) {
			return (pow(_vec1.x, 2) + pow(_vec1.y, 2));
		}
		

		 float LengthSq() {
			return (pow(x, 2) + pow(y, 2));
		}
		

		static float Distance(Vector2& _vec1,Vector2& _vec2) {
			return (sqrt(pow(_vec1.x - _vec2.x, 2) + pow(_vec1.y- _vec2.y, 2)
			));
		}

		static float Dot(Vector2& _vec1, Vector2& _vec2) {
			auto a = _vec1.x * _vec2.x;
			auto b = _vec1.y * _vec2.y;
			return (a + b);
		}

		static float AngleBetweenVectorRadians(Vector2& _vec1, Vector2& _vec2) {
			return acos(Dot(_vec1, _vec2));
		}

		static float AngleBetweenVectorDegrees(Vector2& _vec1, Vector2& _vec2) {
			return ToDegrees( acos(Dot(_vec1, _vec2)));
		}



	private:

	};



	class Vector3
	{
	public:
		float x, y, z;
		Vector3(): x(0.0f), y(0.0f), z(0.0f) {}
		Vector3(float _x, float _y, float _z): x(_x), y(_y), z(_z) {}
		~Vector3() {}



		Vector3 Normalize() {
			Vector3 temp = Vector3(x, y,z);
			x = x / Length(temp);
			y = y / Length(temp);
			return *this;
		}

		static float Length(Vector3& _vec1) {
			return (sqrt(pow(_vec1.x, 2) + pow(_vec1.y, 2)+ pow(_vec1.z, 2)));
		}

		static float LengthSq(Vector3& _vec1) {
			return ((pow(_vec1.x, 2) + pow(_vec1.y, 2)+ pow(_vec1.z, 2)));
		}

		static Vector3 CrossProduct(Vector3& _a, Vector3& _b) {
			return Vector3(_a.y * _b.z - _a.z * _b.y, _a.z * _b.x - _a.x * _b.z, _a.x * _b.y - _a.y * _b.x).Normalize();
		}


	private:

	};


}
