#include "mathHold.h"

namespace fission{

	Vec2::~Vec2(){}

	Vec2& Vec2::add(const Vec2& otherVector){
		this->f_x + otherVector.f_x;
		this->f_y + otherVector.f_y;
		return *this;
	}
	Vec2& Vec2::subtract(const Vec2& otherVector){
		this->f_x - otherVector.f_x;
		this->f_y - otherVector.f_y;
		return *this;
	}
	Vec2& Vec2::multiply(const Vec2& otherVector){
		this->f_x * otherVector.f_x;
		this->f_y * otherVector.f_y;
		return *this;
	}
	Vec2& Vec2::divide(const Vec2& otherVector){
		this->f_x / otherVector.f_x;
		this->f_y / otherVector.f_y;
		return *this;
	}

	Vec2& operator+(Vec2 left, const Vec2& right){
		left.add(right);
		return left;
	}
	Vec2& operator-(Vec2 left, const Vec2& right){
		left.add(right);
		return left;
	}
	Vec2& operator*(Vec2 left, const Vec2& right){
		left.multiply(right);
		return left;
	}
	Vec2& operator/(Vec2 left, const Vec2& right){
		left.add(right);
		return left;
	}

	Vec2& Vec2::operator+= (const Vec2& otherVector){
		return add(otherVector);
	}
	Vec2& Vec2::operator-= (const Vec2& otherVector){
		return subtract(otherVector);
	}
	Vec2& Vec2::operator*= (const Vec2& otherVector){
		return multiply(otherVector);
	}
	Vec2& Vec2::operator/= (const Vec2& otherVector){
		return divide(otherVector);
	}

	std::ostream& operator<<(std::ostream& stream, const Vec2& vector){
		stream << "Vector2: (" << vector.f_x << ", " << vector.f_y << ")";
		return stream;
	}


}