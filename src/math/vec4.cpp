#include "mathHold.h"

namespace fission {

	Vec4::~Vec4(){}

	Vec4& Vec4::add(const Vec4& otherVector){
		this->f_x + otherVector.f_x;
		this->f_y + otherVector.f_y;
		this->f_z + otherVector.f_z;
		this->f_w + otherVector.f_w;
		return *this;
	}
	Vec4& Vec4::subtract(const Vec4& otherVector){
		this->f_x - otherVector.f_x;
		this->f_y - otherVector.f_y;
		this->f_z - otherVector.f_z;
		this->f_w - otherVector.f_w;
		return *this;
	}
	Vec4& Vec4::multiply(const Vec4& otherVector){
		this->f_x * otherVector.f_x;
		this->f_y * otherVector.f_y;
		this->f_z * otherVector.f_z;
		this->f_w * otherVector.f_w;
		return *this;
	}
	Vec4& Vec4::divide(const Vec4& otherVector){
		this->f_x / otherVector.f_x;
		this->f_y / otherVector.f_y;
		this->f_z / otherVector.f_z;
		this->f_w / otherVector.f_w;
		return *this;
	}

	Vec4& operator+(Vec4 left, const Vec4& right){
		left.add(right);
		return left;
	}
	Vec4& operator-(Vec4 left, const Vec4& right){
		left.add(right);
		return left;
	}
	Vec4& operator*(Vec4 left, const Vec4& right){
		left.multiply(right);
		return left;
	}
	Vec4& operator/(Vec4 left, const Vec4& right){
		left.add(right);
		return left;
	}

	Vec4& Vec4::operator+= (const Vec4& otherVector){
		return add(otherVector);
	}
	Vec4& Vec4::operator-= (const Vec4& otherVector){
		return subtract(otherVector);
	}
	Vec4& Vec4::operator*= (const Vec4& otherVector){
		return multiply(otherVector);
	}
	Vec4& Vec4::operator/= (const Vec4& otherVector){
		return divide(otherVector);
	}

	std::ostream& operator<<(std::ostream& stream, const Vec4& vector){
		stream << "Vector2: (" << vector.f_x << ", " << vector.f_y << ", " << vector.f_z << ")";
		return stream;
	}

}