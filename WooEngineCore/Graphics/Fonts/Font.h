#pragma once

#include <string>
#include "../../External/FreeType-gl/freetype-gl.h"

namespace Woo {
	namespace Graphics {
		class Font {
		private:
			ftgl::texture_atlas_t* m_textureAtlas;
			ftgl::texture_font_t* m_textureFont;
			unsigned short m_fontSize;
			std::string m_fontPath;
			std::string m_fontName;
		public:
			Font(std::string& fontName, std::string& fontPath);
			Font(std::string& fontName, unsigned short fontSize, std::string& fontPath);
			~Font();
			inline const unsigned int GetFontID() const { return m_textureAtlas->id; };
			inline ftgl::texture_font_t* GetFontTexture() const { return m_textureFont; };
			inline const std::string& GetFontName() const { return m_fontName; };
		};
	}
}