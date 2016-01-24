#pragma once

#include "MathWoo.h"
#include "Buffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Renderer.h"

namespace Woo {
	namespace Graphics {

		struct VertexData {
			Math::Vector3 position;
			Math::Vector4 color;
		};
		
		class Renderable2D{
		protected:
			Math::Vector3 m_position;
			Math::Vector2 m_size;
			Math::Vector4 m_color;

		public:
			Renderable2D();
			Renderable2D(Math::Vector3 position, Math::Vector2 size, Math::Vector4 color) 
				:m_position(position), m_size(size), m_color(color)
			{
				
			};

			virtual ~Renderable2D() {};

			virtual void SubmitSelf(Renderer2D* myRenderer) const
			{
				myRenderer->Submit(this);
			}
		
			inline const Math::Vector3& GetPosition() const { return m_position; };
			inline const Math::Vector2& GetSize() const { return m_size; };
			inline const Math::Vector4& GetColor() const { return m_color; };

			
		};
	}
}
