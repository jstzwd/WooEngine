#pragma once

#include "Renderable.h"

namespace Woo {
	namespace Graphics {
		class Renderer2D {
		protected:
			virtual void Submit(Renderable2D* sprite) = 0;
			virtual void Flush() = 0;
		};
	}
}