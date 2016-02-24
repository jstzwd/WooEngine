#pragma once

#include "Renderable.h"
#include "..\Fonts\FontPool.h"

namespace Woo {
	namespace Graphics {
		class Text : public Renderable2D {
		public:
			std::string m_textString;
		    Font* m_font;
		public:
			Text(std::string textString, Math::Vector3 position, Math::Vector4 color, std::string& fontName);
			void SubmitSelf(Renderer2D* myRenderer) const;
			bool IsFontValid(Font* font, std::string& fontName);
		};
	}
}
