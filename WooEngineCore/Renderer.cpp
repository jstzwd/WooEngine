#include "Renderer.h"

namespace Woo{
	namespace Graphics {
		Renderer2D::Renderer2D() 
		{
			m_matrixStack.push_back(Math::Matrice4::identity);
			m_topMatrix = &m_matrixStack.back();
		}

		void Renderer2D::Push(const Math::Matrice4& newMatrix, bool isChild)
		{
			if (isChild)
			{
				m_matrixStack.push_back(m_matrixStack.back()*newMatrix);
			}
			else 
			{
				m_matrixStack.push_back(newMatrix);
			}
			m_topMatrix = &m_matrixStack.back();
		}

		void Renderer2D::Pop() 
		{
			if (m_matrixStack.size() <= 1)
				return;
			m_matrixStack.pop_back();
			m_topMatrix = &m_matrixStack.back();
		}
	}
}