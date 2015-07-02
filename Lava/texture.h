#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <iostream>
#include <stb_image.h>

class Texture
{
public:
	Texture(const std::string &fileName);
	Texture(const std::string &fileName, int width, int height, glm::vec3 position); // TODO: Sprite constructor (Add vertices!)

	void Bind(unsigned int unit);

	virtual ~Texture();
protected:
private:
	Texture(const Texture &other) {}
	Texture &operator= (const Texture &rhs) {}

	void RenderTexture();

	GLuint m_texture;
	bool isSprite;
};

#endif TEXTURE_H