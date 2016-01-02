#pragma once
#include "MathW.h"

namespace Woo {
	namespace Math {
		struct Matrice4 {
			float elements[16];

			Matrice4();
			Matrice4(float diagonal);

			
			Matrice4& Multiply(const Matrice4& other);
			Matrice4 operator*(const Matrice4& other);
			Matrice4 operator*=(const Matrice4& other);

			static Matrice4 Orthographic(float left, float right, float top, float bottom, float near, float far);
			static Matrice4 Perspective(float fieldOfViewDegree, float cameraRatio, float near, float far);

			static Matrice4 Translate(const Vector3& translation);
			static Matrice4 Rotate(const float degree, const Vector3& axis);
			static Matrice4 Scale(const Vector3& scale);

			static Matrice4 identity;


		};
	}
}
