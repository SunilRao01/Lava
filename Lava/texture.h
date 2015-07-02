#pragma once

#include <string>
#include <GL\glew.h>
#include <iostream>
#include "stb_image.h"
#include <cassert>

class Texture
{
public:
	Texture(const std::string &fileName);

	void Bind(unsigned int unit);

	virtual ~Texture();
protected:
private:
	Texture(const Texture &other) {}
	Texture &operator= (const Texture &rhs) {}

	GLuint m_texture;
};

