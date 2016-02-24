#include "FontPool.h"

namespace Woo {
	namespace Graphics {
		std::vector<Font*> FontPool::m_fonts;

		void FontPool::AddFont(Font* newFont)
		{
			m_fonts.push_back(newFont);
		}
		
		Font* FontPool::GetFont(std::string& fontName)
		{
			for (Font* font : m_fonts) 
			{
				if(font->GetFontName()==fontName)
				{
					return font;
				}
			}
			return nullptr;
		}

		void FontPool::ClearFonts()
		{
			for(Font* font : m_fonts)
			{
				delete font;
			}
		}
	}
}