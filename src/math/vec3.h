#pragma once
#include <iostream>

namespace fission{

	struct Vec3{

		float f_x, f_y, f_z;

		Vec3(const float& x, const float& y, const float& z) : f_x(x), f_y(y), f_z(z){}
		~Vec3();

		Vec3& add(const Vec3& otherVector);
		Vec3& subtract(const Vec3& otherVector);
		Vec3& multiply(const Vec3& otherVector);
		Vec3& divide(const Vec3& otherVector);

		friend Vec3& operator+(Vec3 left, const Vec3& right);
		friend Vec3& operator-(Vec3 left, const Vec3& right);
		friend Vec3& operator*(Vec3 left, const Vec3& right);
		friend Vec3& operator/(Vec3 left, const Vec3& right);

		Vec3& operator+= (const Vec3& otherVector);
		Vec3& operator-= (const Vec3& otherVector);
		Vec3& operator*= (const Vec3& otherVector);
		Vec3& operator/= (const Vec3& otherVector);

		friend std::ostream& operator<<(std::ostream& stream, const Vec3& vector);

	};

}