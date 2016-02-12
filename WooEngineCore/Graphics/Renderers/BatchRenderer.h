#pragma once

#include <deque>
#include "Renderer.h"
#include "..\Renderables\Renderable.h"
#include "..\..\External\FreeType-gl\freetype-gl.h"

namespace Woo {
	namespace Graphics {

#define GRAPHICS_RENDERER_MAX_SPRITES 10000
#define GRAPHICS_RENDERER_VERTEX_SIZE sizeof(VertexData)
#define GRAPHICS_RENDERER_SPRITE_SIZE GRAPHICS_RENDERER_VERTEX_SIZE*4
#define GRAPHICS_RENDERER_MAX_BUFFER_SIZE GRAPHICS_RENDERER_MAX_SPRITES*GRAPHICS_RENDERER_SPRITE_SIZE
#define GRAPHICS_RENDERER_INDICES_SIZE GRAPHICS_RENDERER_MAX_SPRITES*6

#define GRAPHICS_SHADER_POSITION 0
#define GRAPHICS_SHADER_UV 1
#define GRAPHICS_SHADER_COLOR 2
#define GRAPHICS_SHADER_TEXTURENUMBER 3

		class BatchRenderer2D : public Renderer2D {
		private:
			IndexBuffer* m_myIBO;
			GLsizei m_indexCount;
			GLuint m_myVAO;
			GLuint m_myVBO;

			VertexData* m_buffer;

			std::vector<GLuint> m_textures;

			ftgl::texture_atlas_t* m_textureAtlas;
			ftgl::texture_font_t* m_textureFont;

		protected:
			void Initialize();
		public:
			BatchRenderer2D();
			~BatchRenderer2D();
			void RenderText(const std::string& textString, const Math::Vector3& position, const Math::Vector4& color) override;
			void Submit(const Renderable2D* sprite) override;
			void Flush() override;
			void Begin() override;
			void End() override;

		};
	 }
}