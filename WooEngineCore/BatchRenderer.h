#pragma once

#include <deque>
#include "Renderer.h"

namespace Woo {
	namespace Graphics {

#define GRAPHICS_RENDERER_MAX_SPRITES 10000
#define GRAPHICS_RENDERER_VERTEX_SIZE sizeof(VertexData)
#define GRAPHICS_RENDERER_SPRITE_SIZE GRAPHICS_RENDERER_VERTEX_SIZE*4
#define GRAPHICS_RENDERER_MAX_BUFFER_SIZE GRAPHICS_RENDERER_MAX_SPRITES*GRAPHICS_RENDERER_SPRITE_SIZE
#define GRAPHICS_RENDERER_INDICES_SIZE GRAPHICS_RENDERER_MAX_SPRITES*6

#define GRAPHICS_SHADER_POSITION 0
#define GRAPHICS_SHADER_COLOR 1

		class BatchRenderer2D : public Renderer2D {
		private:
			IndexBuffer* m_myIBO;
			GLsizei m_indexCount;
			GLuint m_myVAO;
			GLuint m_myVBO;
		protected:
			void Initialize();
		public:
			BatchRenderer2D();
			~BatchRenderer2D();
			void Submit(Renderable2D* sprite) override;
			void Flush() override;


		};
	 }
}