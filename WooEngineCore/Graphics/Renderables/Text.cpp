#include "Text.h"

namespace Woo {
	namespace Graphics {
		Text::Text(std::string textString, Math::Vector3 position, Math::Vector4 color, std::string& fontName) 
			:Renderable2D(), m_textString(textString), m_font(FontPool::GetFont(fontName))
		{
			m_position = position;
			m_color = color;
			IsFontValid(m_font, fontName);
		}

		void Text::SubmitSelf(Renderer2D* myRenderer) const
		{
 			myRenderer->RenderText(m_textString, m_position, m_color, m_font);
		}

		bool Text::IsFontValid(Font* font, std::string& fontName) 
		{
			if(m_font!=nullptr)
			{
				return true;
			}
			std::cout << "There is no font named " << fontName << std::endl;
			m_font = FontPool::GetFont(std::string("arial"));
			return false;
		}
		
	}
}