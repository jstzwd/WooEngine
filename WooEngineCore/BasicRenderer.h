#pragma once

#include <deque>
#include "Renderer.h"
#include "StaticSprite.h"

namespace Woo {
	namespace Graphics {
		class BasicRenderer2D : public Renderer2D {
		protected:
			std::deque<StaticSprite*> m_renderable2Ds;
		public:
			void Submit(Renderable2D* sprite) override;
			void Flush() override;
		};
	}
}