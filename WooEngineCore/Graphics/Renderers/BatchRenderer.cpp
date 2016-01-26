#include "BatchRenderer.h"

namespace Woo{
	namespace Graphics {
		BatchRenderer2D::BatchRenderer2D()
		{
			Initialize();
		}

		BatchRenderer2D::~BatchRenderer2D() 
		{
			delete m_myIBO;
			glDeleteBuffers(1, &m_myVBO);
			glDeleteVertexArrays(1, &m_myVAO);
		}
		void BatchRenderer2D::Initialize()
		{
			glGenVertexArrays(1, &m_myVAO);
			glGenBuffers(1, &m_myVBO);
			glBindVertexArray(m_myVAO);
			glBindBuffer(GL_ARRAY_BUFFER, m_myVBO);
			glBufferData(GL_ARRAY_BUFFER, GRAPHICS_RENDERER_MAX_BUFFER_SIZE, nullptr, GL_DYNAMIC_DRAW);
			glEnableVertexAttribArray(GRAPHICS_SHADER_POSITION);
			glEnableVertexAttribArray(GRAPHICS_SHADER_COLOR);
			glVertexAttribPointer(GRAPHICS_SHADER_POSITION, 3, GL_FLOAT, GL_FALSE, GRAPHICS_RENDERER_VERTEX_SIZE, (const GLvoid*) 0);
			glVertexAttribPointer(GRAPHICS_SHADER_COLOR, 4, GL_FLOAT, GL_FALSE, GRAPHICS_RENDERER_VERTEX_SIZE, (const GLvoid*)(3*sizeof(GLfloat)));
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			GLushort indices[GRAPHICS_RENDERER_INDICES_SIZE];
			int index=0;
			for (int i = 0; i < GRAPHICS_RENDERER_INDICES_SIZE; i+=6) {
				indices[i] = index;
				indices[i + 1] = index + 1;
				indices[i + 2] = index + 2;

				indices[i + 3] = index + 2;
				indices[i + 4] = index + 3;
				indices[i + 5] = index;

				index += 4;
			}
			m_myIBO = new IndexBuffer(indices, GRAPHICS_RENDERER_INDICES_SIZE);

		}

		void BatchRenderer2D::Begin() 
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_myVBO);
			m_buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		}
		void BatchRenderer2D::Submit(const Renderable2D* sprite) 
		{
			
			const Math::Vector3 position = sprite->GetPosition();
			const Math::Vector2 size = sprite->GetSize();


			m_buffer->position = (*m_topMatrix)*Math::Vector3(position.x - size.x / 2, position.y - size.y / 2, 0);
			m_buffer->color = sprite->GetColor();
			m_buffer++;

			m_buffer->position = (*m_topMatrix)* Math::Vector3(position.x + size.x / 2, position.y - size.y / 2, 0);
			m_buffer->color = sprite->GetColor();
			m_buffer++;

			m_buffer->position = (*m_topMatrix)*Math::Vector3(position.x + size.x / 2, position.y + size.y / 2, 0);
			m_buffer->color = sprite->GetColor();
			m_buffer++;

			m_buffer->position = (*m_topMatrix)*Math::Vector3(position.x - size.x / 2, position.y + size.y / 2, 0);
			m_buffer->color = sprite->GetColor();
			m_buffer++;

			m_indexCount += 6;
		}

		void BatchRenderer2D::End()
		{
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}


		void BatchRenderer2D::Flush()
		{
			glBindVertexArray(m_myVAO);
			m_myIBO->Bind();

			glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_SHORT, 0);

			m_myIBO->UnBind();
			glBindVertexArray(0);
		}
	}
}