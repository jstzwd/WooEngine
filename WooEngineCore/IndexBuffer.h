#pragma once

#include <gl\glew.h>

namespace Woo {
	namespace Graphics {
		class IndexBuffer {
		private:
			GLuint m_bufferID;
			GLuint m_count;
		public:
			IndexBuffer(GLushort* data, GLsizei count);
			void Bind() const;
			void UnBind() const;

		};
	}
}