#pragma once

#include <vector>
#include <gl\glew.h>
#include "Buffer.h"

namespace Woo {
	namespace Graphics {
		class VertexArray {
		private:
			GLuint m_arrayID;
			std::vector<Buffer*> m_buffers;
		public:
			VertexArray();
			~VertexArray();
			void Bind() const;
			void UnBind() const;
			void AddBuffer(Buffer* newBuffer, GLuint index);

		};
	}
}