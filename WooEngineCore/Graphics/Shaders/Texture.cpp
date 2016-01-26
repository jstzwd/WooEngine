#include "Texture.h"

namespace Woo {
	namespace Graphics {
		Texture::Texture(const std::string filePath)
			:m_filePath(filePath)
		{
			Load();
		}
		Texture::~Texture()
		{
		
		}
        void Texture::Load()
		{
			BYTE* pixelData = Utility::LoadImage(m_filePath.c_str(), &m_width, &m_height);

			glGenTextures(1, &m_textureID);
			glBindTexture(GL_TEXTURE_2D, m_textureID);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_BGR, GL_UNSIGNED_BYTE, pixelData);
			glBindTexture(GL_TEXTURE_2D, 0);
		}
		void Texture::Bind() const 
		{
			glBindTexture(GL_TEXTURE_2D, m_textureID);
		}
		void Texture::UnBind() const
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}
}