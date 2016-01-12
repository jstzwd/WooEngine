#include "IndexBuffer.h"

namespace Woo {
	namespace Graphics {
		IndexBuffer::IndexBuffer(GLushort* data, GLsizei count) : m_count(count) {
			glGenBuffers(1, &m_bufferID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(GLushort), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		void IndexBuffer::Bind() const {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
		}

		void IndexBuffer::UnBind() const {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
		GLint IndexBuffer::GetCount() const
		{
			return m_count;
		}
	}
}