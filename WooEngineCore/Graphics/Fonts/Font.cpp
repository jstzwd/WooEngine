#include "Font.h"

namespace Woo {
	namespace Graphics {
		Font::Font(std::string& fontName, std::string& fontPath)
			: m_fontSize(32), m_fontPath(fontPath), m_fontName(fontName)
		{
			m_textureAtlas = texture_atlas_new(512, 512, 2);
			m_textureFont = texture_font_new_from_file(m_textureAtlas, m_fontSize, m_fontPath.c_str());
		}

		Font::Font(std::string& fontName, unsigned short fontSize, std::string& fontPath)
			: m_fontSize(fontSize), m_fontPath(fontPath), m_fontName(fontName)
		{
			m_textureAtlas = texture_atlas_new(512, 512, 2);
			m_textureFont = texture_font_new_from_file(m_textureAtlas, m_fontSize, m_fontPath.c_str());
		}

		Font::~Font()
		{
			delete m_textureAtlas;
			delete m_textureFont;
		}

	}
}