#pragma once

#include <vector>
#include "Font.h"

namespace Woo {
	namespace Graphics {
		class FontPool {
		private:
			static std::vector<Font*> m_fonts;
		public:
			static void AddFont(Font* newFont);
			static Font* GetFont(std::string& fontName);
			static void ClearFonts();
		};
	}
}