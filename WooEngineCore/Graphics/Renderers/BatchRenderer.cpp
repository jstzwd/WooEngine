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
			glEnableVertexAttribArray(GRAPHICS_SHADER_UV);
			glEnableVertexAttribArray(GRAPHICS_SHADER_COLOR);
			glEnableVertexAttribArray(GRAPHICS_SHADER_TEXTURENUMBER);
			glVertexAttribPointer(GRAPHICS_SHADER_POSITION, 3, GL_FLOAT, GL_FALSE, GRAPHICS_RENDERER_VERTEX_SIZE, (const GLvoid*) 0);
			glVertexAttribPointer(GRAPHICS_SHADER_UV, 2, GL_FLOAT,GL_FALSE, GRAPHICS_RENDERER_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData,VertexData::uv)));
			glVertexAttribPointer(GRAPHICS_SHADER_COLOR, 4, GL_FLOAT, GL_FALSE, GRAPHICS_RENDERER_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::color)));
			glVertexAttribPointer(GRAPHICS_SHADER_TEXTURENUMBER, 1, GL_FLOAT, GL_FALSE, GRAPHICS_RENDERER_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::textureNumber)));
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

			m_textureAtlas = texture_atlas_new(512, 512, 1);
			m_textureFont = texture_font_new_from_file(m_textureAtlas, 32, "Arial.tff");

		}

		void BatchRenderer2D::RenderText(const std::string& textString, const Math::Vector3& position, const Math::Vector4& color)
		{
			float textureNumber = 0.f;
			
			bool textureIncluded = false;
			for (int i = 0; i < m_textures.size(); i++)
			{
				if (m_textureAtlas->id == m_textures[i])
				{
					textureNumber = (float)(i + 1);
					textureIncluded = true;
					break;
				}
			}
			if (!textureIncluded)
			{
				if (m_textures.size() >= 32)
				{
					End();
					Flush();
					Begin();
				}
				m_textures.push_back(m_textureAtlas->id);
				textureNumber = (float)m_textures.size();
			}

			float x = position.x;

			for (int i = 0; i < textString.length(); i++) {
				char character = textString[i];
				texture_glyph_t* glyph = texture_font_get_glyph(m_textureFont, &character);
				if (glyph != NULL) 
				{
					if (i > 0)
					{
						float kerning = texture_glyph_get_kerning(glyph, &textString[i - 1]);
						x += kerning;
					}


				}
				/*
				m_buffer->position = (*m_topMatrix)*Math::Vector3(position.x - size.x / 2, position.y - size.y / 2, 0);
				m_buffer->uv = uvs[0];
				m_buffer->color = color;
				m_buffer->textureNumber = textureNumber;
				m_buffer++;

				m_buffer->position = (*m_topMatrix)* Math::Vector3(position.x + size.x / 2, position.y - size.y / 2, 0);
				m_buffer->uv = uvs[1];
				m_buffer->color = color;
				m_buffer->textureNumber = textureNumber;
				m_buffer++;

				m_buffer->position = (*m_topMatrix)*Math::Vector3(position.x + size.x / 2, position.y + size.y / 2, 0);
				m_buffer->uv = uvs[2];
				m_buffer->color = color;
				m_buffer->textureNumber = textureNumber;
				m_buffer++;

				m_buffer->position = (*m_topMatrix)*Math::Vector3(position.x - size.x / 2, position.y + size.y / 2, 0);
				m_buffer->uv = uvs[3];
				m_buffer->color = color;
				m_buffer->textureNumber = textureNumber;
				m_buffer++;

				m_indexCount += 6;
				*/
			}
		}

		void BatchRenderer2D::Begin() 
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_myVBO);
			m_buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		}
		void BatchRenderer2D::Submit(const Renderable2D* sprite) 
		{
			
			const Math::Vector3& position = sprite->GetPosition();
			const Math::Vector2& size = sprite->GetSize();
			const std::vector<Math::Vector2>& uvs = sprite->GetUVs();
			const Math::Vector4& color = sprite->GetColor();
			const GLuint textureID = sprite->GetTextureID();

			float textureNumber = 0.f;
			if (textureID > 0)
			{
				bool textureIncluded = false;
				for (int i = 0; i < m_textures.size();i++)
				{
					if (textureID == m_textures[i]) 
					{
						textureNumber = (float)(i + 1);
						textureIncluded = true;
						break;
					}
				}
				if (!textureIncluded) 
				{
					if(m_textures.size()>=32)
					{
						End();
						Flush();
						Begin();
					}
					m_textures.push_back(textureID);
					textureNumber = (float)m_textures.size();
				}
			}
			m_buffer->position = (*m_topMatrix)*Math::Vector3(position.x - size.x / 2, position.y - size.y / 2, 0);
			m_buffer->uv = uvs[0];
			m_buffer->color = color;
			m_buffer->textureNumber = textureNumber;
			m_buffer++;

			m_buffer->position = (*m_topMatrix)* Math::Vector3(position.x + size.x / 2, position.y - size.y / 2, 0);
			m_buffer->uv = uvs[1];
			m_buffer->color = color;
			m_buffer->textureNumber = textureNumber;
			m_buffer++;

			m_buffer->position = (*m_topMatrix)*Math::Vector3(position.x + size.x / 2, position.y + size.y / 2, 0);
			m_buffer->uv = uvs[2];
			m_buffer->color = color;
			m_buffer->textureNumber = textureNumber;
			m_buffer++;

			m_buffer->position = (*m_topMatrix)*Math::Vector3(position.x - size.x / 2, position.y + size.y / 2, 0);
			m_buffer->uv = uvs[3];
			m_buffer->color = color;
			m_buffer->textureNumber = textureNumber;
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
			for (int i = 0; i < m_textures.size(); i++) 
			{
				glActiveTexture(GL_TEXTURE0 + i);
				glBindTexture(GL_TEXTURE_2D, m_textures[i]);
			}
			glBindVertexArray(m_myVAO);
			m_myIBO->Bind();

			glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_SHORT, 0);

			m_myIBO->UnBind();
			glBindVertexArray(0);

			m_indexCount = 0;
		}
	}
}