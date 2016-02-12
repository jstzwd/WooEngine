#pragma once

#include "Renderable.h"

namespace Woo {
	namespace Graphics {
		class Text : public Renderable2D {
		public:
			std::string m_textString;
			
		public:
			Text(std::string textString, Math::Vector3 position, Math::Vector4 color);
			void SubmitSelf(Renderer2D* myRenderer) const;

		};
	}
}
