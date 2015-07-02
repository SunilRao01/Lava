#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "Shader.h"
#include "mesh.h"
#include "texture.h"


int main(int argc, char **argv)
{
	Display display(800, 600, "Test");

	// Set up basic diffuse shader for textures
	Shader shader("./res/basicShader");
	
	// Set up sonic sprite
	Vertex sonicVertices[] = {	Vertex(glm::vec3(-0.05,-0.1, 0), glm::vec2(0.0, 1.0)),
								Vertex(glm::vec3(-0.05, 0.1, 0), glm::vec2(0.0, 0.0)),
								Vertex(glm::vec3(0.05, 0.1, 0),    glm::vec2(1.0, 0.0)),
								Vertex(glm::vec3(0.05, -0.1, 0), glm::vec2(1.0, 1.0)) };
	Mesh sonicMesh(sonicVertices, sizeof(sonicVertices) / sizeof(sonicVertices[0]));
	Texture sonicSprite("./res/s_sonic.png", true);

	// Set up twin peaks background
	Vertex twinpeaksVertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 1.0)),
		Vertex(glm::vec3(-0.5, 0.5, 0), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3(0.5, 0.5, 0), glm::vec2(1.0, 0.0)),
		Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 1.0)) };
	Mesh twinpeaksMesh(twinpeaksVertices, sizeof(twinpeaksVertices) / sizeof(twinpeaksVertices[0]));
	Texture twinpeaksTexture("./res/t_twinpeaks.jpg", false);

	while (!display.IsClosed())
	{
		display.Clear(0.5f, 0.6f, 0.7f, 1.0f);
		
		shader.Bind();

		twinpeaksTexture.Bind(0);
		twinpeaksMesh.Draw();

		sonicSprite.Bind(0);
		sonicMesh.Draw();

		display.Update();
	}
	
	exit(0);
	return 0;
}