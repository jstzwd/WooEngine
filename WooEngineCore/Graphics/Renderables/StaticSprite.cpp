#include "StaticSprite.h"

namespace Woo {
	namespace Graphics {
		StaticSprite::StaticSprite(Math::Vector3 position, Math::Vector2 size, Math::Vector4 color)
			:Renderable2D(position,size,color)
		{
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
			m_myVAO->AddBuffer(new VertexBuffer(vertices, 12, 3), 0);
			m_myVAO->AddBuffer(new VertexBuffer(colors, 16, 4), 1);
		}

		StaticSprite::~StaticSprite() {
			delete m_myVAO;
			delete m_myIBO;
		}

	}
}