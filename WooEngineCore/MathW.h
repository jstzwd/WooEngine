#pragma once

#define _USE_MATH_DEFINES

#include <math.h>
#include "Vector.h"



inline float ToRadian(float degree) {
	return (degree / 180.f)*M_PI;
}