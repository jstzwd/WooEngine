#include "Matrice4.h"

namespace Woo {
	namespace Math {
		Matrice4::Matrice4() {
			for (int i = 0; i < 16; i++) {
				elements[i] = 0.f;
			}
		}
		Matrice4::Matrice4(float diagonal) {
			for (int i = 0; i < 16; i++) {
				elements[i] = 0.f;
			}
			elements[0] = diagonal;
			elements[5] = diagonal;
			elements[10] = diagonal;
			elements[15] = diagonal;
		}
		Matrice4& Matrice4::Multiply(const Matrice4& other) {
			for (int x = 0; x < 4; x++) {
				for (int y = 0; y < 4; y++) {
					float newElement=0.f;
					for (int factor = 0; factor < 4; factor++) {
						newElement += this->elements[x + factor * 4] * other.elements[factor + y * 4];
					}
					this->elements[x + y * 4] = newElement;
				}
			}
			return *this;
		}
		Matrice4 Matrice4::operator*(const Matrice4& other) {
			Matrice4 result;
			for (int x = 0; x < 4; x++) {
				for (int y = 0; y < 4; y++) {
					float newElement = 0.f;
					for (int factor = 0; factor < 4; factor++) {
						newElement += this->elements[x + factor * 4] * other.elements[factor + y * 4];
					}
					result.elements[x + y * 4] = newElement;
				}
			}
			return result;
		}

		Matrice4 Matrice4::operator*=(const Matrice4& other) {
			return Multiply(other);
		}

		Matrice4 Matrice4::Orthographic(float left, float right, float top, float bottom, float near, float far) {
			Matrice4 result(1.0f);
			result.elements[0] = 2 / (right - left);
			result.elements[5] = 2 / (top - bottom);
			result.elements[10] = -2 / (far - near);
			result.elements[12] = -(right + left) / (right - left);
			result.elements[13] = -(top + bottom) / (top - bottom);
			result.elements[14] = -(far + near) / (far - near);
			result.elements[15] = 1.f;
			return result;
		}

		Matrice4 Matrice4::Perspective(float fieldOfViewDegree, float cameraRatio, float near, float far) {
			Matrice4 result(1.0f);
			result.elements[0] = 1 / (cameraRatio*tan(ToRadian(fieldOfViewDegree)));
			result.elements[5] = 1 / tan(ToRadian(fieldOfViewDegree));
			result.elements[10] = -(far+near) / (far-near);
			result.elements[11] = -1.f;
			result.elements[14] = -2*far*near/(far-near);
			return result;
		}

		Matrice4 Matrice4::Translate(const Vector3& translation) {
			Matrice4 result(1.0f);
			result.elements[12] = translation.x;
			result.elements[13] = translation.y;
			result.elements[14] = translation.z;
			return result;
		}

		Matrice4 Matrice4::Rotate(const float degree, const Vector3& axis) {
			Matrice4 result(1.0f);
			float r = ToRadian(degree);
			float c = cos(r);
			float s = sin(r);
			float oc = 1.f - c;
			
			float x = axis.x;
			float y = axis.y;
			float z = axis.z;
			result.elements[0] = x*oc + c;
			result.elements[1] = y*x*oc + z*s;
			result.elements[2] = x*z*oc - y*s;

			result.elements[4] = x*y*oc - z*s;
			result.elements[5] = y*oc + c;
			result.elements[6] = y*z*oc + x*s;

			result.elements[8] = x*z*oc + y*s;
			result.elements[9] = y*z*oc - x*s;
			result.elements[10] = z*oc + c;

			return result;
			return result;
		}

		Matrice4 Matrice4::Scale(const Vector3& scale) {
			Matrice4 result(1.0f);
			result.elements[0] = scale.x;
			result.elements[5] = scale.y;
			result.elements[10] = scale.z;
			return result;
		}

		Matrice4 Matrice4::identity(1.f);
	}
}