#pragma once

#include <string>
#include <GL\glew.h>
#include <iostream>
#include <cassert>
#include <stb_image.h>

class Texture
{
public:
	Texture(const std::string &fileName, bool isSprite);

	void Bind(unsigned int unit);

	virtual ~Texture();
protected:
private:
	Texture(const Texture &other) {}
	Texture &operator= (const Texture &rhs) {}

	GLuint m_texture;
	bool isSprite;
};

