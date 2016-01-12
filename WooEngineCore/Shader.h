#pragma once

#include <iostream>
#include <vector>
#include <gl\glew.h>
#include "FileUtility.h"
#include "MathWoo.h"

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

			void SetUniform1(const GLchar* name, float value);
			void SetUniform1(const GLchar* name, int value);
			void SetUniform2(const GLchar* name, const Math::Vector2 valueVector2);
			void SetUniform3(const GLchar* name, const Math::Vector3 valueVector3);
			void SetUniform4(const GLchar* name, const Math::Vector4 valueVector4);
			void SetUniform4(const GLchar* name, const Math::Matrice4 valueMatrice);

			void Enable() const;
			void Disable() const;
		private:
			GLint GetUniformLocation(const GLchar* name);

			GLuint Load();
		};
    }
}