#include "Layer.h"

namespace Woo{
	namespace Graphics {
		Layer::Layer(Renderer2D* renderer, Shader* shader, Math::Matrice4 projectionMatrix)
			:m_renderer(renderer), m_shader(shader), m_projectionMatrix(projectionMatrix)
		{
			//m_shader->Enable();
			m_shader->SetUniform4("pr_matrix", m_projectionMatrix);
			//m_shader->Disable();
		}

		Layer::~Layer()
		{
			
			delete m_shader;
			delete m_renderer;

			for (int i = 0; i < m_renderable2Ds.size();i++) {
				delete m_renderable2Ds[i];
			}
		}

		void Layer::AddRenderable2D(Renderable2D* newSprite)
		{
			m_renderable2Ds.push_back(newSprite);
		}

		void Layer::RenderLayer() 
		{
			m_shader->Enable();
			m_renderer->Begin();
			for(Renderable2D* sprite : m_renderable2Ds){
				sprite->SubmitSelf(m_renderer);
			//	m_renderer->Submit(sprite);
			}
			m_renderer->End();
			m_renderer->Flush();
		}
	}
}