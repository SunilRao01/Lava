#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "Shader.h"
#include "mesh.h"
#include "texture.h"


int main(int argc, char **argv)
{
	Display display(800, 600, "Hello World");
	
	Vertex vertices[] = {	Vertex(glm::vec3(-0.5,-0.5, 0), glm::vec2(0.0, 0.0)),
							Vertex(glm::vec3(0, 0.5, 0),    glm::vec2(0.5, 1.0)),
							Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)) };
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./res/basicShader");
	Texture texture("./res/t_twinpeaks.jpg");

	// Test 

	while (!display.IsClosed())
	{
		display.Clear(0.5f, 0.6f, 0.7f, 1.0f);
		
		shader.Bind();
		texture.Bind(0);
		mesh.Draw();

		display.Update();
	}
	
	exit(0);
	return 0;
}