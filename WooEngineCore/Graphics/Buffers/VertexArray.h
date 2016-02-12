#pragma once

#include <vector>
#include <gl\glew.h>
#include "VertexBuffer.h"

namespace Woo {
	namespace Graphics {
		class VertexArray {
		private:
			GLuint m_arrayID;
			std::vector<VertexBuffer*> m_buffers;
		public:
			VertexArray();
			~VertexArray();
			void Bind() const;
			void UnBind() const;
			void AddBuffer(VertexBuffer* newBuffer, GLuint index);

		};
	}
}