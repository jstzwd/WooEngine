#include "VertexBuffer.h"

namespace Woo {
	namespace Graphics {
		VertexBuffer::VertexBuffer(GLfloat* data, GLsizei count, GLuint componentCount) : m_componentCount(componentCount) {
			glGenBuffers(1, &m_bufferID);
			glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
			glBufferData(GL_ARRAY_BUFFER, count*sizeof(float), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		VertexBuffer::~VertexBuffer()
		{
			glDeleteBuffers(1, &m_bufferID);
		}
		void VertexBuffer::Bind() const {
			glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
		}

		void VertexBuffer::UnBind() const {
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		GLuint VertexBuffer::GetComponentCount() const
		{
			return m_componentCount;
		}
	}
}