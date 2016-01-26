#pragma once

#include <FreeImage.h>
#include <GL\glew.h>
#include <string>
#include "..\..\Utility\ImageUtility.h"

namespace Woo {
	namespace Graphics {
		class Texture {
		private:
			GLuint m_textureID;
			std::string m_filePath;
			GLsizei m_width, m_height;
		public:
			Texture(const std::string filePath);
			~Texture();
			void Load();
			void Bind() const;
			void UnBind() const;

			inline unsigned int GetWidth() const { return m_width; }
			inline unsigned int GetHeight() const { return m_height; }

		};
	}
}