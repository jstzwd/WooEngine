#pragma once

#include "Renderable.h"

namespace Woo {
	namespace Graphics {
		class Renderer2D {
		public:
			virtual void Begin() {};
			virtual void Submit(const Renderable2D* sprite) = 0;
			virtual void End() {};
			virtual void Flush() = 0;
			
		};
	}
}