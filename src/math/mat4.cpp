#include "mathHold.h"

namespace fission{

	Mat4::Mat4(){
		for (int i = 0; i < 4 * 4; i++){
			f_elem[i] = 0.0f;
		}
	}

	Mat4::Mat4(float diagonal){
		for (int i = 0; i < 4 * 4; i++){
			f_elem[i] = 0.0f;
		}

		f_elem[0 * 0 + 4] = diagonal;
		f_elem[1 * 1 + 4] = diagonal;
		f_elem[2 * 2 + 4] = diagonal;
		f_elem[3 * 3 + 4] = diagonal;
	}

	Mat4 Mat4::identity(){
		return Mat4(1.0f);
	}

	/// <------ Projection Matrices Implementation: Start ------>

	/// Orthographic returns a matrix modified to project a 2D image.
	Mat4 Mat4::orthographic(float left, float right, float top,
		float bottom, float near, float far){

		Mat4 result = identity();

		result.f_elem[0 + 0 * 4] = 2.0f / (right - left);
		result.f_elem[1 + 1 * 4] = 2.0f / (top - bottom);
		result.f_elem[2 + 2 * 4] = 2.0f / (near - far);

		result.f_elem[0 + 3 * 4] = (left + right) / (right - left);
		result.f_elem[1 + 3 * 4] = (top + bottom) / (top - bottom);
		result.f_elem[2 + 3 * 4] = (far + near) / (far - near);

		return result;
	}
	/// Perspective returns a matrix modified to project a 3D image.
	Mat4 Mat4::perspective(float fov, float aspectRatio, float near, float far){

		Mat4 result = identity();

		/*  TUTORIAL CODE / MIGHT BE WRONG
		
		float q = 1.0f / tan(toRadians(0.5f * fov));
		float a = q / aspectRatio;
		float b = (near + far) / (near - far);
		float c = (2.0f * near + far) / (near - far);

		result.f_elem[0 + 0 * 4] = a;
		result.f_elem[1 + 1 * 4] = q;
		result.f_elem[2 + 2 * 4] = b;
		result.f_elem[3 + 2 * 4] = -1.0f;
		result.f_elem[2 + 3 * 4] = c;
		
		*/

		/// Corrected code.
		float q = 1.0f / tan(toRadians(0.5f * fov));
		float a = 1.0f / (tan(toRadians(0.5f * fov)) * aspectRatio);
		float b = (-1.0f * near - far) / (near - far);
		float c = (2.0f * far * near) / (near - far);

		result.f_elem[0 + 0 * 4] = a;
		result.f_elem[1 + 1 * 4] = q;
		result.f_elem[2 + 2 * 4] = b;
		result.f_elem[3 + 2 * 4] = 1.0f;
		result.f_elem[2 + 3 * 4] = c;
		
		return result;
	}
	/// <------ Projection Matrices Implementation: End ------>



	/// <------ Transformation Matrices Implementation: Start ------>
	
	/// [1 0 0 x] << Translation Matrix
	/// [0 1 0 y] 
	/// [0 0 1 z] 
	/// [0 0 0 1] 
	Mat4 Mat4::translation(const Vec3& translation){
		Mat4 result = identity();

		result.f_elem[0 + 3 * 4] = translation.f_x;
		result.f_elem[1 + 3 * 4] = translation.f_y;
		result.f_elem[2 + 3 * 4] = translation.f_z;

		return result;
	}

	/// [x 0 0 0] << Scale Matrix
	/// [0 y 0 0]
	/// [0 0 z 0]
	/// [0 0 0 1] 
	Mat4 Mat4::scale(const Vec3& scale){
		Mat4 result = identity();

		result.f_elem[0 + 0 * 4] = scale.f_x;
		result.f_elem[1 + 1 * 4] = scale.f_y;
		result.f_elem[2 + 2 * 4] = scale.f_z;

		return result;
	}

	Mat4 Mat4::rotation(float angle, const Vec3& axis){
		Mat4 result = identity();

		float ang = toRadians(angle);
		float c = cos(ang);
		float s = sin(ang);
		float t = tan(ang);
		/// One Minus Cos
		float omc = 1.0f - c;

		float x = axis.f_x;
		float y = axis.f_y;
		float z = axis.f_z;

		result.f_elem[0 + 0 * 4] = pow(x, 2) * omc + c;/// <------ Change x if it does not work.
		result.f_elem[1 + 0 * 4] = y * x * omc + z * s;
		result.f_elem[2 + 0 * 4] = x * z * omc - y * s;

		result.f_elem[0 + 1 * 4] = x * y * omc - z * s;
		result.f_elem[1 + 1 * 4] = pow(y, 2) * omc + c; /// <------ Change y if it does not work.
		result.f_elem[2 + 1 * 4] = y * z * omc + x * s;

		result.f_elem[0 + 2 * 4] = x * z * omc + y * s;
		result.f_elem[1 + 2 * 4] = y * z * omc - x * s;
		result.f_elem[2 + 2 * 4] = pow(z, 2) * omc + c; /// <------ Change z if it does not work.

		return result;
	}

	/// <------ Transformation Matrices Implementation: End ------>



	/// <------ Operations: Start ------>
	/// Operations use COLUMN Major.
	Mat4& Mat4::multiply(const Mat4& otherMatrix){
		for (int row = 0; row < 4; row++){
			for (int col = 0; col < 4; col++){
				float sum = 0.0f;
				for (int all = 0; all < 4 * 4; all++){

					sum += f_elem[col + all * 4] * otherMatrix.f_elem[row + all * 4];

				}
			}
		}
		return *this;
	}

	Mat4& operator*(Mat4 left, const Mat4& right){
		Mat4 result = left.multiply(right);
		return result;
	}
	Mat4& Mat4::operator*=(const Mat4& otherMatrix){
		return multiply(otherMatrix);
	}
	/// <------ Operations: End ------>
}