#pragma once

#include <gl\glew.h>

namespace Woo {
	namespace Graphics {
		class Buffer {
		private:
			GLuint m_bufferID;
			GLuint m_componentCount;
		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
			void Bind() const;
			void UnBind() const;

		};
	}
}