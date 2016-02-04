#include "Sprite.h"

namespace Woo {
	namespace Graphics {
		Sprite::Sprite(Math::Vector3 position, Math::Vector2 size, Math::Vector4 color)
			:Renderable2D(position, size, color)
		{
		
		}
		Sprite::Sprite(Math::Vector3 position, Math::Vector2 size, Texture* texture)
			:Renderable2D(position, size, Math::Vector4(1,0,1,1))
		{
			m_texture = texture;
		}
	}
}