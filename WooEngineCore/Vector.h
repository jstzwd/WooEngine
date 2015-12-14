#pragma once
#include <iostream>
namespace Woo {
	namespace Math {
		struct Vector2{
			float x,y;

			Vector2();
			Vector2(const float& x, const float& y);

			Vector2& operator=(const Vector2& other);
			Vector2 operator+(const Vector2& other);
			Vector2 operator-(const Vector2& other);
			Vector2 operator*(const int& other);
			Vector2 operator*(const float& other);
			Vector2 operator*(const double& other);
			Vector2 operator/(const int& other);
			Vector2 operator/(const float& other);
			Vector2 operator/(const double& other);

			
			Vector2 operator+=(const Vector2& other);
			Vector2 operator-=(const Vector2& other);
			Vector2 operator*=(const int& other);
			Vector2 operator*=(const float& other);
			Vector2 operator*=(const double& other);
			Vector2 operator/=(const int& other);
			Vector2 operator/=(const float& other);
			Vector2 operator/=(const double& other);
			bool operator==(const Vector2& other);
			bool operator!=(const Vector2& other);
			friend std::ostream& operator<<(std::ostream& stream, const Vector2& thisVector) {
				stream << "Vector2(" << thisVector.x << ", " << thisVector.y << ")";
				return stream;
			}
			static Vector2 zero;

		};

		struct Vector3 {
			float x, y, z;
			Vector3();
			Vector3(const float& x, const float&y, const float& z);

			Vector3& operator=(const Vector3& other);
			Vector3 operator+(const Vector3& other);
			Vector3 operator-(const Vector3& other);
			Vector3 operator*(const int& other);
			Vector3 operator*(const float& other);
			Vector3 operator*(const double& other);
			Vector3 operator/(const int& other);
			Vector3 operator/(const float& other);
			Vector3 operator/(const double& other);


			Vector3 operator+=(const Vector3& other);
			Vector3 operator-=(const Vector3& other);
			Vector3 operator*=(const int& other);
			Vector3 operator*=(const float& other);
			Vector3 operator*=(const double& other);
			Vector3 operator/=(const int& other);
			Vector3 operator/=(const float& other);
			Vector3 operator/=(const double& other);
			bool operator==(const Vector3& other);
			bool operator!=(const Vector3& other);
			friend std::ostream& operator<<(std::ostream& stream, const Vector3& thisVector) {
				stream << "Vector3(" << thisVector.x << ", " << thisVector.y << ", " << thisVector.z << ")";
				return stream;
			};
			static Vector3 zero;
		};

		struct Vector4 {
			float x, y, z, a;
			Vector4();
			Vector4(const float& x, const float&y, const float& z, const float& a);

			Vector4& operator=(const Vector4& other);
			Vector4 operator+(const Vector4& other);
			Vector4 operator-(const Vector4& other);
			Vector4 operator*(const int& other);
			Vector4 operator*(const float& other);
			Vector4 operator*(const double& other);
			Vector4 operator/(const int& other);
			Vector4 operator/(const float& other);
			Vector4 operator/(const double& other);


			Vector4 operator+=(const Vector4& other);
			Vector4 operator-=(const Vector4& other);
			Vector4 operator*=(const int& other);
			Vector4 operator*=(const float& other);
			Vector4 operator*=(const double& other);
			Vector4 operator/=(const int& other);
			Vector4 operator/=(const float& other);
			Vector4 operator/=(const double& other);
			bool operator==(const Vector4& other);
			bool operator!=(const Vector4& other);

			friend std::ostream& operator<<(std::ostream& stream, const Vector4& thisVector) {
				stream << "Vector4(" << thisVector.x << ", " << thisVector.y << ", " << thisVector.z << ", " << thisVector.a << ")";
				return stream;
			};
			static Vector4 zero;
		};
	
	}

}