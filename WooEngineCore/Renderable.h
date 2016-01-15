#pragma once

#include "MathWoo.h"
#include "Buffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

namespace Woo {
	namespace Graphics {
		struct VertexData {
			Math::Vector3 position;
			Math::Vector4 color;
		};
		class Renderable2D{
		protected:
			Math::Vector3 m_position;
			Math::Vector2 m_size;
			Math::Vector4 m_color;

			VertexArray* m_myVAO;
			IndexBuffer* m_myIBO;
		public:
			Renderable2D(Math::Vector3 position, Math::Vector2 size, Math::Vector4 color) {
				GLfloat vertices[] = {
					position.x - size.x / 2,position.y - size.y / 2,0,
					position.x + size.x / 2,position.y - size.y / 2,0,
					position.x + size.x / 2,position.y + size.y / 2,0,
					position.x - size.x / 2,position.y + size.y / 2,0
				};
				GLfloat colors[] = {
					color.x,color.y,color.z,color.w,
					color.x,color.y,color.z,color.w,
					color.x,color.y,color.z,color.w,
					color.x,color.y,color.z,color.w
				};
				GLushort indices[] = { 0,1,2,2,3,0 };
				m_myVAO = new VertexArray();
				m_myIBO = new IndexBuffer(indices, 6);
				m_myVAO->AddBuffer(new Buffer(vertices, 12, 3), 0);
				m_myVAO->AddBuffer(new Buffer(colors, 16, 4), 1);
			};

			~Renderable2D() {
				delete m_myVAO;
				delete m_myIBO;
			};

		
			inline const Math::Vector3& GetPosition() const { return m_position; };
			inline const Math::Vector2& GetSize() const { return m_size; };
			inline const Math::Vector4& GetColor() const { return m_color; };

			inline const VertexArray* GetMyVAO() const { return m_myVAO; };
			inline const IndexBuffer* GetMyIBO() const { return m_myIBO; };
		};
	}
}
