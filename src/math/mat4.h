#pragma once

#include <iostream>

namespace fission{

	struct Mat4{
		float f_elem[4 * 4];

		/// Constructor
		Mat4();
		Mat4(float diagonal);
		~Mat4(){};

		/// Starting Identity Matrix
		static Mat4 identity();

		/// Projection Matrices.
		static Mat4 orthographic(float left, float right, float top,
			float bottom, float near, float far);
		static Mat4 perspective(float fov, float aspectRatio, float near, float far);

		/// Transformation Matrices.
		static Mat4 translation(const Vec3& translation);
		static Mat4 scale(const Vec3& scale);
		static Mat4 rotation(float angle, const Vec3& axis);
		
		/// Operations
		Mat4& multiply(const Mat4& otherMatrix);
		friend Mat4& operator*(Mat4 left, const Mat4& right);
		Mat4& operator*=(const Mat4& otherMatrix);

	};

}