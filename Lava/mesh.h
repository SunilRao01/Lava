#pragma once

#include <glm\glm.hpp>
#include <GL\glew.h>

class Vertex
{
public:
	Vertex(const glm::vec3 &pos, const glm::vec2 &texCoord)
	{
		this->position = pos;
		this->textureCoordinates = texCoord;
	};

	inline glm::vec3 *GetPosition() { return &position; }
	inline glm::vec2 *GetTexCoords() { return &textureCoordinates; }

protected:
private:
	glm::vec3 position;
	glm::vec2 textureCoordinates;
};

class Mesh
{
public:
	Mesh(Vertex *vertices, unsigned int numVertices);

	void Draw();

	virtual ~Mesh();

protected:

private:
	Mesh(const Mesh &other);
	Mesh &operator= (const Mesh &other);

	enum
	{
		POSITION_VB,
		TEXTURECOORDINATES_VB,
		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};

