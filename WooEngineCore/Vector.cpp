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
	}
}