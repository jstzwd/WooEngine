#pragma once

#include <gl\glew.h>
#include "..\..\Math\MathWoo.h"
#include <vector>

namespace Woo {
	namespace Graphics {
		class Renderable2D;
		class Renderer2D {
		protected:
			std::vector<Math::Matrice4> m_matrixStack;
			Math::Matrice4* m_topMatrix;
		public:
			Renderer2D();
			void Push(const Math::Matrice4& newMatrix, bool isChild);
			void Pop();
			virtual void RenderText(const std::string& textString, const Math::Vector3& position, const Math::Vector4& color) {};
			virtual void Begin() {};
			virtual void Submit(const Renderable2D* sprite) = 0;
			virtual void End() {};
			virtual void Flush() = 0;
			
		};
	}
}