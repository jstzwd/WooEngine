#pragma once

#include "Renderable.h"
#include <vector>
#include "..\..\Math\Vector.h"

namespace Woo {
	namespace Graphics {
		class ParentRenderable2D : public Renderable2D {
		public:
			std::vector<Renderable2D*> m_childRenderable2Ds;
			Math::Matrice4 m_transformMatrix;
		public:
			ParentRenderable2D(Math::Matrice4& transformMatrix, Math::Vector3& position, Math::Vector2& size, Math::Vector4 color);
			~ParentRenderable2D();
			void Add(Renderable2D* newRenderable2D);
			void SubmitSelf(Renderer2D* myRenderer) const override;
		};
	}
}