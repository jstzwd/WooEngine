#pragma once

#include "Renderer.h"
#include "Renderable.h"
#include "ParentRenderable.h"
#include "Shader.h"
#include <vector>

namespace Woo{
	namespace Graphics {
		class Layer {
		protected:
			Renderer2D* m_renderer;
			std::vector<Renderable2D*> m_renderable2Ds;
			Shader* m_shader;
			Math::Matrice4 m_projectionMatrix;
		public:
			//Layer();
			Layer(Renderer2D* renderer, Shader* shader, Math::Matrice4 projectionMatrix);
			virtual ~Layer();
			virtual void AddRenderable2D(Renderable2D* newSprite);
			virtual void RenderLayer();
		};
	}
}
