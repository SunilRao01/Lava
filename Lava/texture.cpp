#include "texture.h"

Texture::Texture(const std::string &fileName)
{
	int width, height, numComponents;
	unsigned char *imageData = stbi_load(fileName.c_str(), &width, &height, &numComponents, 4);

	if (imageData == NULL)
	{
		std::cerr << "Texture loading failed for file: " << fileName << std::endl;
	}

	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Enabled alpha
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTexImage2D(GL_TEXTURE_2D, 0 /* Used for mi-maping, making textures lower res when further away, etc.*/,
		GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	stbi_image_free(imageData);
}

// TODO: Sprite transform implementation
Texture::Texture(const std::string &fileName, int spriteWidth, int spriteHeight, glm::vec3 spritePosition)
{
	int width, height, numComponents;
	unsigned char *imageData = stbi_load((fileName).c_str(), &width, &height, &numComponents, STBI_rgb_alpha);

	if (imageData == NULL)
	{
		std::cerr << "Texture loading failed for file: " << fileName << std::endl;
	}

	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	
	
	// Enabled alpha
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTexImage2D(GL_TEXTURE_2D, 0 /* Used for mi-maping, making textures lower res when further away, etc.*/, 
		GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	stbi_image_free(imageData);
}

void Texture::RenderTexture()
{

}

Texture::~Texture()
{
	glDeleteTextures(1, &m_texture);
}

void Texture::Bind(unsigned int unit)
{
	assert(unit >= 0 && unit <= 31);
	
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, m_texture);
}