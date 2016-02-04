#pragma once

#include "..\..\Math\MathWoo.h"
#include "..\Buffers\Buffer.h"
#include "..\Buffers\IndexBuffer.h"
#include "..\Buffers\VertexArray.h"
#include "..\Renderers\Renderer.h"
#include "..\Shaders\Texture.h"

namespace Woo {
	namespace Graphics {

		struct VertexData {
			Math::Vector3 position;
			Math::Vector2 uv;
			Math::Vector4 color;
			float textureNumber;
		};
		
		class Renderable2D{
		protected:
			Math::Vector3 m_position;
			Math::Vector2 m_size;
			Math::Vector4 m_color;
			std::vector<Math::Vector2> m_uvs;
			Texture* m_texture;
		public:
			Renderable2D();
			Renderable2D(Math::Vector3 position, Math::Vector2 size, Math::Vector4 color) 
				:m_position(position), m_size(size), m_color(color)
			{
				InitializeUV();
			};
			void InitializeUV()
			{
				m_uvs.push_back(Math::Vector2(0, 0));
				m_uvs.push_back(Math::Vector2(1, 0));
				m_uvs.push_back(Math::Vector2(1, 1));
				m_uvs.push_back(Math::Vector2(0, 1));
			}
			virtual ~Renderable2D() {};

			virtual void SubmitSelf(Renderer2D* myRenderer) const
			{
				myRenderer->Submit(this);
			}
		
			inline const Math::Vector3& GetPosition() const { return m_position; }
			inline const Math::Vector2& GetSize() const { return m_size; }
			inline const std::vector<Math::Vector2>& GetUVs() const {return m_uvs; }
			inline const Math::Vector4& GetColor() const { return m_color; }
			inline const GLuint GetTextureID() const { return m_texture != nullptr ? m_texture->GetTextureID() : 0; }
			
		};
	}
}
