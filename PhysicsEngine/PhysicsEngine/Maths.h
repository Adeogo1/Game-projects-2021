#pragma once
#include <iostream>
#include <algorithm>
using namespace std;



namespace Maths {

	template <typename T>
	T Clamp(const T& _value, const T& _lower, const T& _Upper) {
		return min(_Upper, max(_lower, _value));
	}

	class Vector2
	{
	public:
		float x = 0, y = 0;
		Vector2():x(0.0f),y(0.0f) {}
		Vector2(float _x, float _y):x(_x),y(_y) {}

		Vector2 Zero() {
			x = 0;
			y = 0;
			return Vector2(x, y);
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
		
	private:

	};
}
