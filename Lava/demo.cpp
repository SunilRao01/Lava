#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include <SDL2\SDL.h>

int main(int argc, char **argv)
{
	std::cout << "Application has started..." << std::endl;
	
	Display display(800, 600, "Test");

	// Set up basic diffuse shader for textures
	Shader shader("./res/basicShader");

	// Set up twin peaks background texture
	Vertex twinpeaksVertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 1.0)),
		Vertex(glm::vec3(-0.5, 0.5, 0), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3(0.5, 0.5, 0), glm::vec2(1.0, 0.0)),
		Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 1.0)) };
	Mesh twinpeaksMesh(twinpeaksVertices, sizeof(twinpeaksVertices) / sizeof(twinpeaksVertices[0]));
	Texture twinpeaksTexture("./res/t_twinpeaks.jpg");

	// Set up sonic sprite
	Vertex sonicVertices[] = { Vertex(glm::vec3(-0.05, -0.1, 0), glm::vec2(0.0, 1.0)),
		Vertex(glm::vec3(-0.05, 0.1, 0), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3(0.05, 0.1, 0), glm::vec2(1.0, 0.0)),
		Vertex(glm::vec3(0.05, -0.1, 0), glm::vec2(1.0, 1.0)) };
	Mesh sonicMesh(sonicVertices, sizeof(sonicVertices) / sizeof(sonicVertices[0]));
	Texture sonicSprite("./res/s_sonic.png", 5, 20, glm::vec3(0.0, 0.0, 0.0));

	Transform transform;
	float counter = 0.0f;

	while (!display.IsClosed())
	{
		display.Clear(0.5f, 0.6f, 0.7f, 1.0f);
		
		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.GetPosition().x = sinCounter;
		transform.GetRotation().z = counter;
		transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

		shader.Update(transform);
		shader.Bind();

		twinpeaksTexture.Bind(0);
		twinpeaksMesh.Draw();

		sonicSprite.Bind(0);
		sonicMesh.Draw();
		
		display.Update();
		counter += 0.0005f; // By processing speed, use timer in future
	}
	
	exit(0);
	return 0;
}