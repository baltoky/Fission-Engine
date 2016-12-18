#pragma once
#include <iostream>

namespace fission{
	struct Vec2
	{
		float f_x, f_y;

		Vec2(const float& x, const float& y) : f_x(x), f_y(y){}
		~Vec2();

		Vec2& add(const Vec2& otherVector);
		Vec2& subtract(const Vec2& otherVector);
		Vec2& multiply(const Vec2& otherVector);
		Vec2& divide(const Vec2& otherVector);

		friend Vec2& operator+( Vec2 left, const Vec2& right);
		friend Vec2& operator-(Vec2 left, const Vec2& right);
		friend Vec2& operator*(Vec2 left, const Vec2& right);
		friend Vec2& operator/(Vec2 left, const Vec2& right);

		Vec2& operator+= (const Vec2& otherVector);
		Vec2& operator-= (const Vec2& otherVector);
		Vec2& operator*= (const Vec2& otherVector);
		Vec2& operator/= (const Vec2& otherVector);

		friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector);


	};

}