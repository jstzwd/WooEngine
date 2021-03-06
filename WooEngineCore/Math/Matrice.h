#pragma once
#include "Math.h"
#include "Vector.h"

namespace Woo {
	namespace Math {
		struct Matrice4 {
			union {
				float elements[16];
				Vector4 columns[4];
			};
			
			
			Matrice4();
			Matrice4(float diagonal);

			
			Matrice4& Multiply(const Matrice4& other);
			Matrice4 operator*(const Matrice4& other);
			Vector3 operator*(const Vector3& other);
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
