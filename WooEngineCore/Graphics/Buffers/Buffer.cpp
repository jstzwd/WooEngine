#include "Buffer.h"

namespace Woo {
	namespace Graphics {
		Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount) : m_componentCount(componentCount) {
			glGenBuffers(1, &m_bufferID);
			glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
			glBufferData(GL_ARRAY_BUFFER, count*sizeof(float), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		Buffer::~Buffer()
		{
			glDeleteBuffers(1, &m_bufferID);
		}
		void Buffer::Bind() const {
			glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
		}

		void Buffer::UnBind() const {
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		GLuint Buffer::GetComponentCount() const
		{
			return m_componentCount;
		}
	}
}