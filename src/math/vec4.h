#pragma once
#include <iostream>

namespace fission{

	struct Vec4{
		float f_x, f_y, f_z, f_w;

		Vec4(const float& x, const float& y, const float& z, const float& w) : f_x(x), f_y(y), f_z(z), f_w(w){}
		~Vec4();

		Vec4& add(const Vec4& otherVector);
		Vec4& subtract(const Vec4& otherVector);
		Vec4& multiply(const Vec4& otherVector);
		Vec4& divide(const Vec4& otherVector);

		friend Vec4& operator+(Vec4 left, const Vec4& right);
		friend Vec4& operator-(Vec4 left, const Vec4& right);
		friend Vec4& operator*(Vec4 left, const Vec4& right);
		friend Vec4& operator/(Vec4 left, const Vec4& right);

		Vec4& operator+= (const Vec4& otherVector);
		Vec4& operator-= (const Vec4& otherVector);
		Vec4& operator*= (const Vec4& otherVector);
		Vec4& operator/= (const Vec4& otherVector);

		friend std::ostream& operator<<(std::ostream& stream, const Vec4& vector);
	};
}