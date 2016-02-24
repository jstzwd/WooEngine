#include "ParentRenderable.h"

namespace Woo {
	namespace Graphics {
		ParentRenderable2D::ParentRenderable2D(Math::Matrice4& transformMatrix, Math::Vector3& position, Math::Vector2& size, Math::Vector4 color)
			:m_transformMatrix(transformMatrix), Renderable2D(position,size,color)
		{
		
		}
		ParentRenderable2D::~ParentRenderable2D()
		{
			for(Renderable2D* childSprite:m_childRenderable2Ds)
			{
				delete childSprite;
			}
		}
		void ParentRenderable2D::Add(Renderable2D* newRenderable2D)
		{
			m_childRenderable2Ds.push_back(newRenderable2D);
		}
		
		void ParentRenderable2D::SubmitSelf(Renderer2D* myRenderer) const
		{
			myRenderer->Push(m_transformMatrix,true);
			for (Renderable2D* childSprite : m_childRenderable2Ds) {
				childSprite->SubmitSelf(myRenderer);
			}
			myRenderer->Pop();
		}
		
	}
}