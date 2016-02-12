#pragma once

#include <gl\glew.h>

namespace Woo {
	namespace Graphics {
		class VertexBuffer {
		private:
			GLuint m_bufferID;
			GLuint m_componentCount;
		public:
			VertexBuffer(GLfloat* data, GLsizei count, GLuint componentCount);
			~VertexBuffer();
			void Bind() const;
			void UnBind() const;
			GLuint GetComponentCount() const;
		};
	}
}