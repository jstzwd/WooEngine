#include "Shader.h"

namespace Woo{
	namespace Graphics {
	    Shader::Shader(const char* vertPath, const char* fragPath):m_vertPath(vertPath),m_fragPath(fragPath){
			m_shaderID = Load();
	    }

		Shader::~Shader() {
			glDeleteProgram(m_shaderID);
		}

		GLuint Shader::Load() {
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertString = Utility::ReadFile(m_vertPath);
		    std::string fragString = Utility::ReadFile(m_fragPath);
			const char* vertSource = vertString.c_str();
			const char* fragSource = fragString.c_str();

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
		GLint Shader::GetUniformLocation(const GLchar* name)
		{
			return glGetUniformLocation(m_shaderID, name);
		}

		void Shader::SetUniform1(const GLchar* name, float value)
		{
			glUniform1f(GetUniformLocation(name), value);
		}
		void Shader::SetUniform1(const GLchar* name, int value)
		{
			glUniform1i(GetUniformLocation(name), value);
		}
		void Shader::SetUniform1(const GLchar* name, int count, int* value)
		{
			glUniform1iv(GetUniformLocation(name), count, value);
		}
		void Shader::SetUniform1(const GLchar* name, int count, float* value)
		{
			glUniform1fv(GetUniformLocation(name), count, value);
		}
		void Shader::SetUniform2(const GLchar* name, Math::Vector2 valueVector)
		{
			glUniform2f(GetUniformLocation(name), valueVector.x, valueVector.y);
		}
		void Shader::SetUniform3(const GLchar* name, Math::Vector3 valueVector)
		{
			glUniform3f(GetUniformLocation(name), valueVector.x, valueVector.y, valueVector.z);
		}
		void Shader::SetUniform4(const GLchar* name, Math::Vector4 valueVector)
		{
			glUniform4f(GetUniformLocation(name), valueVector.x,valueVector.y, valueVector.z, valueVector.w);
		}
		void Shader::SetUniform4(const GLchar* name, Math::Matrice4 valueMatrix)
		{
			glUniformMatrix4fv(GetUniformLocation(name),1,GL_FALSE,valueMatrix.elements);
		}
		void Shader::Enable() const {
			glUseProgram(m_shaderID);
		}

		void Shader::Disable() const {
			glUseProgram(0);
		}
	}
}