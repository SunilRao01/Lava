#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <GL\glew.h>
#include "transform.h"
#include "camera.h"

class Shader
{
public:
	Shader(const std::string &fileName);

	void Bind();
	void Update(const Transform &transform, const Camera &camera);

	virtual ~Shader();
protected:

private:
	static const unsigned int NUM_SHADERS = 2;

	Shader(const Shader &other) {}
	Shader &operator= (const Shader &other) {}

	enum 
	{
		TRANFORM_U,

		NUM_UNIFORMS
	};

	GLuint program;
	GLuint shaders[NUM_SHADERS];
	GLuint uniforms[NUM_UNIFORMS];
};

#endif