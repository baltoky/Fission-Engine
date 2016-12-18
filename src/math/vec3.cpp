#include "mathHold.h"

namespace fission{

	Vec3::~Vec3(){}

	Vec3& Vec3::add(const Vec3& otherVector){
		this->f_x + otherVector.f_x;
		this->f_y + otherVector.f_y;
		this->f_z + otherVector.f_z;
		return *this;
	}
	Vec3& Vec3::subtract(const Vec3& otherVector){
		this->f_x - otherVector.f_x;
		this->f_y - otherVector.f_y;
		this->f_z - otherVector.f_z;
		return *this;
	}
	Vec3& Vec3::multiply(const Vec3& otherVector){
		this->f_x * otherVector.f_x;
		this->f_y * otherVector.f_y;
		this->f_z * otherVector.f_z;
		return *this;
	}
	Vec3& Vec3::divide(const Vec3& otherVector){
		this->f_x / otherVector.f_x;
		this->f_y / otherVector.f_y;
		this->f_z / otherVector.f_z;
		return *this;
	}

	Vec3& operator+(Vec3 left, const Vec3& right){
		left.add(right);
		return left;
	}
	Vec3& operator-(Vec3 left, const Vec3& right){
		left.add(right);
		return left;
	}
	Vec3& operator*(Vec3 left, const Vec3& right){
		left.multiply(right);
		return left;
	}
	Vec3& operator/(Vec3 left, const Vec3& right){
		left.add(right);
		return left;
	}

	Vec3& Vec3::operator+= (const Vec3& otherVector){
		return add(otherVector);
	}
	Vec3& Vec3::operator-= (const Vec3& otherVector){
		return subtract(otherVector);
	}
	Vec3& Vec3::operator*= (const Vec3& otherVector){
		return multiply(otherVector);
	}
	Vec3& Vec3::operator/= (const Vec3& otherVector){
		return divide(otherVector);
	}

	std::ostream& operator<<(std::ostream& stream, const Vec3& vector){
		stream << "Vector2: (" << vector.f_x << ", " << vector.f_y << ", " << vector.f_z << ")";
		return stream;
	}

}