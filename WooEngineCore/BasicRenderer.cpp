#include "BasicRenderer.h"

namespace Woo {
	namespace Graphics {
		void BasicRenderer2D::Submit(Renderable2D* sprite)
		{
			m_renderable2Ds.push_back(sprite);
		}
		void BasicRenderer2D::Flush()
		{
			while (!m_renderable2Ds.empty()) {
				Renderable2D* thisSprite = m_renderable2Ds.front();
				thisSprite->GetMyVAO()->Bind();
				thisSprite->GetMyIBO()->Bind();

				glDrawElements(GL_TRIANGLES, thisSprite->GetMyIBO()->GetCount(), GL_UNSIGNED_SHORT, 0);
				thisSprite->GetMyVAO()->UnBind();
				thisSprite->GetMyIBO()->UnBind();
				m_renderable2Ds.pop_front();

			}
		}
	}
}