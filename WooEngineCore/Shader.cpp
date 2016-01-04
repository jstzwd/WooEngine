#include "Shader.h"

namespace Woo{
	namespace Graphics {
	    Shader::Shader(const char* vertPath, const char* fragPath):m_VertPath(vertPath),m_FragPath(fragPath){
			shaderID = Load();
	    }

		GLuint Shader::Load() {
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			const char* vertSource = Utility::ReadFile(m_VertPath).c_str();
			const char* fragSource = Utility::ReadFile(m_FragPath).c_str();

			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);

			GLint resultVertex;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &resultVertex);
			if (resultVertex == GL_FALSE) {
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << "Failed to compile vertex shader!"<<std::endl<<&error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;
			}

			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);

			GLint resultFrag;
			glGetShaderiv(fragment, GL_COMPILE_STATUS, &resultFrag);
			if (resultFrag == GL_FALSE) {
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << "Failed to compile fragment shader!"<<std::endl<<&error[0] << std::endl;
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}

		void Shader::Enable() const {
			glUseProgram(shaderID);
		}

		void Shader::Disable() const {
			glUseProgram(0);
		}
	}
}