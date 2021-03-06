#include "VertexArray.h"

namespace Woo {
	namespace Graphics {
		VertexArray::VertexArray()
		{
			glGenVertexArrays(1, &m_arrayID);
		}
		VertexArray::~VertexArray() 
		{
			for (int i = 0; i < m_buffers.size(); i++) {
				delete m_buffers[i];
			}
			glDeleteVertexArrays(1, &m_arrayID);
		}
		void VertexArray::Bind() const {
			glBindVertexArray(m_arrayID);
		}
		void VertexArray::UnBind() const {
			glBindVertexArray(0);
		}
		void VertexArray::AddBuffer(VertexBuffer* newBuffer, GLuint index)
		{
			Bind();
			newBuffer->Bind();
			
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, newBuffer->GetComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

			newBuffer->UnBind();
			UnBind();

			m_buffers.push_back(newBuffer);
		}
	}
}