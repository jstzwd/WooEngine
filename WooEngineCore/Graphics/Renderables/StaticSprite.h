#pragma once

#include "Renderable.h"

namespace Woo {
	namespace Graphics {

		class StaticSprite : public Renderable2D {
		protected:
			VertexArray* m_myVAO;
			IndexBuffer* m_myIBO;
		public:
			StaticSprite(Math::Vector3 position, Math::Vector2 size, Math::Vector4 color);
			~StaticSprite(); 

			inline const VertexArray* GetMyVAO() const { return m_myVAO; };
			inline const IndexBuffer* GetMyIBO() const { return m_myIBO; };
		};
	}

}