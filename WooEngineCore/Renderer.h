#pragma once

#include "Renderable.h"
#include <vector>

namespace Woo {
	namespace Graphics {
		class Renderer2D {
		protected:
			std::vector<Math::Matrice4> m_matrixStack;
			Math::Matrice4* m_topMatrix;
		public:
			Renderer2D();
			void Push(const Math::Matrice4& newMatrix, bool inGroup);
			void Pop();
			virtual void Begin() {};
			virtual void Submit(const Renderable2D* sprite) = 0;
			virtual void End() {};
			virtual void Flush() = 0;
			
		};
	}
}