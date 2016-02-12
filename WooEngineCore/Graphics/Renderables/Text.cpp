#include "Text.h"

namespace Woo {
	namespace Graphics {
		Text::Text(std::string textString, Math::Vector3 position, Math::Vector4 color) 
			:Renderable2D(), m_textString(textString)
		{
			m_position = position;
			m_color = color;
		}

		void Text::SubmitSelf(Renderer2D* myRenderer) const
		{
			myRenderer->RenderText(m_textString, m_position, m_color);
		}
		
	}
}