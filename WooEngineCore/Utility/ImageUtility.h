#pragma once

#include <FreeImage.h>
#include <GL\glew.h>
#include <string>

namespace Woo {
	namespace Utility {
		BYTE* LoadImage(const char* filename, GLsizei* width, GLsizei* height);
	}
}