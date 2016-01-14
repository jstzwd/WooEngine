#pragma once

#include <deque>
#include "Renderer.h"

namespace Woo {
	namespace Graphics {
		class BatchRenderer2D : public Renderer2D {
		private:
			VertexArray m_myVAO;
			IndexBuffer* m_myIBO;
			GLsizei m_indexCount;
			GLuint m_myVBO;
		protected:
			std::deque<Renderable2D*> m_renderable2Ds;
		public:
			void Submit(Renderable2D* sprite) override;
			void Flush() override;
		};
	}
}