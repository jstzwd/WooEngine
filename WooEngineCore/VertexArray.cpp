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
		}
		void VertexArray::Bind() const {
			glBindVertexArray(m_arrayID);
		}
		void VertexArray::UnBind() const {
			glBindVertexArray(0);
		}
		void VertexArray::AddBuffer(Buffer* newBuffer, GLuint index)
		{
			Bind();
			newBuffer->Bind();
			
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, newBuffer->GetComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

			newBuffer->UnBind();
			UnBind();
		}
	}
}