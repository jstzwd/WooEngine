#pragma once

#include <iostream>
#include <vector>
#include <gl\glew.h>
#include "FileUtility.h"

namespace Woo{
    namespace Graphics{
		class Shader {
		private:
			GLuint m_shaderID;
			const char* m_vertPath;
			const char* m_fragPath;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void Enable() const;
			void Disable() const;
		private:
			GLuint Load();

		};
    }
}