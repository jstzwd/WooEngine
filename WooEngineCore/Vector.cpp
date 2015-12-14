#include "Vector.h"

namespace Woo {
	namespace Math {
		Vector2::Vector2() {
			this->x = 0.f;
			this->y = 0.f;
		}
		Vector2::Vector2(const float& x,const float& y) {
			this->x = x;
			this->y = y;
		}
		Vector2& Vector2::operator=(const Vector2& other) {
			this->x = other.x;
			this->y = other.y;
			return *this;
		}
		Vector2 Vector2::operator+(const Vector2& other) {
			Vector2 temp(this->x,this->y);
			temp.x += other.x;
			temp.y += other.y;
			return temp;
		}
		Vector2 Vector2::operator-(const Vector2& other) {
			Vector2 temp(this->x, this->y);
			temp.x -= other.x;
			temp.y -= other.y;
			return temp;
		}
		Vector2 Vector2::operator*(const int& other) {
			Vector2 temp(this->x, this->y);
			temp.x *= other;
			temp.y *= other;
			return temp;
		}
		Vector2 Vector2::operator*(const float& other) {
			Vector2 temp(this->x, this->y);
			temp.x *= other;
			temp.y *= other;
			return temp;
		}
		Vector2 Vector2::operator*(const double& other) {
			Vector2 temp(this->x, this->y);
			temp.x *= other;
			temp.y *= other;
			return temp;
		}
		Vector2 Vector2::operator/(const int& other) {
			Vector2 temp(this->x, this->y);
			temp.x /= other;
			temp.y /= other;
			return temp;
		}
		Vector2 Vector2::operator/(const float& other) {
			Vector2 temp(this->x, this->y);
			temp.x /= other;
			temp.y /= other;
			return temp;
		}
		Vector2 Vector2::operator/(const double& other) {
			Vector2 temp(this->x, this->y);
			temp.x /= other;
			temp.y /= other;
			return temp;
		}
		Vector2 Vector2::operator+=(const Vector2& other) {
			this->x += other.x;
			this->y += other.y;
			return *this;
		}
		Vector2 Vector2::operator-=(const Vector2& other) {
			this->x -= other.x;
			this->y -= other.y;
			return *this;
		}
		Vector2 Vector2::operator*=(const int& other) {
			this->x *= other;
			this->y *= other;
			return *this;
		}
		Vector2 Vector2::operator*=(const float& other) {
			this->x *= other;
			this->y *= other;
			return *this;
		}
		Vector2 Vector2::operator*=(const double& other) {
			this->x *= other;
			this->y *= other;
			return *this;
		}
		Vector2 Vector2::operator/=(const int& other) {
			this->x /= other;
			this->y /= other;
			return *this;
		}
		Vector2 Vector2::operator/=(const float& other) {
			this->x /= other;
			this->y /= other;
			return *this;
		}
		Vector2 Vector2::operator/=(const double& other) {
			this->x /= other;
			this->y /= other;
			return *this;
		}
		bool Vector2::operator==(const Vector2& other) {
			return (this->x == other.x) && (this->y == other.y);
		}
		bool Vector2::operator!=(const Vector2& other) {
			return (this->x != other.x) || (this->y != other.y);
		}
		Vector2 Vector2::zero(0, 0);

		Vector3::Vector3() {
			this->x = 0.f;
			this->y = 0.f;
			this->z = 0.f;
		}
		Vector3::Vector3(const float& x, const float& y, const float& z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		Vector3& Vector3::operator=(const Vector3& other) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			return *this;
		}
		Vector3 Vector3::operator+(const Vector3& other) {
			Vector3 temp(this->x, this->y, this->z);
			temp.x += other.x;
			temp.y += other.y;
			temp.z += other.z;
			return temp;
		}
		Vector3 Vector3::operator-(const Vector3& other) {
			Vector3 temp(this->x, this->y, this->z);
			temp.x -= other.x;
			temp.y -= other.y;
			temp.z -= other.z;
			return temp;
		}
		Vector3 Vector3::operator*(const int& other) {
			Vector3 temp(this->x, this->y, this->z);
			temp.x *= other;
			temp.y *= other;
			temp.z *= other;
			return temp;
		}
		Vector3 Vector3::operator*(const float& other) {
			Vector3 temp(this->x, this->y, this->z);
			temp.x *= other;
			temp.y *= other;
			temp.z *= other;
			return temp;
		}
		Vector3 Vector3::operator*(const double& other) {
			Vector3 temp(this->x, this->y, this->z);
			temp.x *= other;
			temp.y *= other;
			temp.z *= other;
			return temp;
		}
		Vector3 Vector3::operator/(const int& other) {
			Vector3 temp(this->x, this->y, this->z);
			temp.x /= other;
			temp.y /= other;
			temp.z /= other;
			return temp;
		}
		Vector3 Vector3::operator/(const float& other) {
			Vector3 temp(this->x, this->y, this->z);
			temp.x /= other;
			temp.y /= other;
			temp.z /= other;
			return temp;
		}
		Vector3 Vector3::operator/(const double& other) {
			Vector3 temp(this->x, this->y, this->z);
			temp.x /= other;
			temp.y /= other;
			temp.z /= other;
			return temp;
		}
		Vector3 Vector3::operator+=(const Vector3& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;
		}
		Vector3 Vector3::operator-=(const Vector3& other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return *this;
		}
		Vector3 Vector3::operator*=(const int& other) {
			this->x *= other;
			this->y *= other;
			this->z *= other;
			return *this;
		}
		Vector3 Vector3::operator*=(const float& other) {
			this->x *= other;
			this->y *= other;
			this->z *= other;
			return *this;
		}
		Vector3 Vector3::operator*=(const double& other) {
			this->x *= other;
			this->y *= other;
			this->z *= other;
			return *this;
		}
		Vector3 Vector3::operator/=(const int& other) {
			this->x /= other;
			this->y /= other;
			this->z /= other;
			return *this;
		}
		Vector3 Vector3::operator/=(const float& other) {
			this->x /= other;
			this->y /= other;
			this->z /= other;
			return *this;
		}
		Vector3 Vector3::operator/=(const double& other) {
			this->x /= other;
			this->y /= other;
			this->z /= other;
			return *this;
		}
		bool Vector3::operator==(const Vector3& other) {
			return (this->x == other.x) && (this->y == other.y) && (this->z == other.z);
		}
		bool Vector3::operator!=(const Vector3& other) {
			return (this->x != other.x) || (this->y != other.y) || (this->z != other.z);
		}
		Vector3 Vector3::zero(0, 0, 0);

		Vector4::Vector4() {
			this->x = 0.f;
			this->y = 0.f;
			this->z = 0.f;
			this->a = 0.f;
		}
		Vector4::Vector4(const float& x, const float& y, const float& z, const float& a) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->a = a;
		}
		Vector4& Vector4::operator=(const Vector4& other) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->a = other.a;
			return *this;
		}
		Vector4 Vector4::operator+(const Vector4& other) {
			Vector4 temp(this->x, this->y, this->z, this->a);
			temp.x += other.x;
			temp.y += other.y;
			temp.z += other.z;
			temp.a += other.a;
			return temp;
		}
		Vector4 Vector4::operator-(const Vector4& other) {
			Vector4 temp(this->x, this->y, this->z, this->a);
			temp.x -= other.x;
			temp.y -= other.y;
			temp.z -= other.z;
			temp.a -= other.a;
			return temp;
		}
		Vector4 Vector4::operator*(const int& other) {
			Vector4 temp(this->x, this->y, this->z, this->a);
			temp.x *= other;
			temp.y *= other;
			temp.z *= other;
			temp.a *= other;
			return temp;
		}
		Vector4 Vector4::operator*(const float& other) {
			Vector4 temp(this->x, this->y, this->z, this->a);
			temp.x *= other;
			temp.y *= other;
			temp.z *= other;
			temp.a *= other;
			return temp;
		}
		Vector4 Vector4::operator*(const double& other) {
			Vector4 temp(this->x, this->y, this->z, this->a);
			temp.x *= other;
			temp.y *= other;
			temp.z *= other;
			temp.a *= other;
			return temp;
		}
		Vector4 Vector4::operator/(const int& other) {
			Vector4 temp(this->x, this->y, this->z, this->a);
			temp.x /= other;
			temp.y /= other;
			temp.z /= other;
			temp.a /= other;
			return temp;
		}
		Vector4 Vector4::operator/(const float& other) {
			Vector4 temp(this->x, this->y, this->z, this->a);
			temp.x /= other;
			temp.y /= other;
			temp.z /= other;
			temp.a /= other;
			return temp;
		}
		Vector4 Vector4::operator/(const double& other) {
			Vector4 temp(this->x, this->y, this->z, this->a);
			temp.x /= other;
			temp.y /= other;
			temp.z /= other;
			temp.a /= other;
			return temp;
		}
		Vector4 Vector4::operator+=(const Vector4& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->a += other.a;
			return *this;
		}
		Vector4 Vector4::operator-=(const Vector4& other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->a -= other.a;
			return *this;
		}
		Vector4 Vector4::operator*=(const int& other) {
			this->x *= other;
			this->y *= other;
			this->z *= other;
			this->a *= other;
			return *this;
		}
		Vector4 Vector4::operator*=(const float& other) {
			this->x *= other;
			this->y *= other;
			this->z *= other;
			this->a *= other;
			return *this;
		}
		Vector4 Vector4::operator*=(const double& other) {
			this->x *= other;
			this->y *= other;
			this->z *= other;
			this->a *= other;
			return *this;
		}
		Vector4 Vector4::operator/=(const int& other) {
			this->x /= other;
			this->y /= other;
			this->z /= other;
			this->a /= other;
			return *this;
		}
		Vector4 Vector4::operator/=(const float& other) {
			this->x /= other;
			this->y /= other;
			this->z /= other;
			this->a /= other;
			return *this;
		}
		Vector4 Vector4::operator/=(const double& other) {
			this->x /= other;
			this->y /= other;
			this->z /= other;
			this->a /= other;
			return *this;
		}
		bool Vector4::operator==(const Vector4& other) {
			return (this->x == other.x) && (this->y == other.y) && (this->z == other.z) && (this->a == other.a);
		}
		bool Vector4::operator!=(const Vector4& other) {
			return (this->x != other.x) || (this->y != other.y) || (this->z != other.z) || (this->a != other.a);
		}
		Vector4 Vector4::zero(0,0,0,0);
	}
}