#pragma once

#define _USE_MATH_DEFINES

#include <math.h>
namespace Woo {
	namespace Math {
		inline float ToRadian(float degree) {
			return (degree / 180.f)*M_PI;
		}
	}
}