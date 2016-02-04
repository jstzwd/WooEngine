#pragma once

#include "Renderable.h"

namespace Woo {
	namespace Graphics {

		class Sprite : public Renderable2D {
		public:
			Sprite(Math::Vector3 position, Math::Vector2 size, Math::Vector4 color);
			Sprite(Math::Vector3 position, Math::Vector2 size, Texture* texture);
		};
	}

}