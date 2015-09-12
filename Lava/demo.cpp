#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"
#include <SDL2\SDL.h>

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char **argv)
{
	std::cout << "Application has started..." << std::endl;
	
	Display display(WIDTH, HEIGHT, "Test");

	/////////////////
	// 2D Demo///////
	/////////////////

	
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
	

	Camera camera(glm::vec3(0, 0, -3), 70.0f, (float) WIDTH / (float) HEIGHT, 0.01f, 1000.0f);

	while (!display.IsClosed())
	{
		display.Clear(0.5f, 0.6f, 0.7f, 1.0f);
		
		/////////////////
		// 2D Demo///////
		/////////////////

		
		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.GetPosition().x = sinCounter;
		transform.GetPosition().z = cosCounter;
		
		transform.GetRotation().x = counter;
		transform.GetRotation().y = counter;
		transform.GetRotation().z = counter;
		//transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

		shader.Update(transform, camera);
		shader.Bind();

		// Layer 1
		twinpeaksTexture.Bind(0);
		twinpeaksMesh.Draw();

		// Layer 2
		sonicSprite.Bind(0);
		sonicMesh.Draw();
		
		
		display.Update();
		counter += 0.0005f; // By processing speed, use timer in future
	}
	
	exit(0);
	return 0;
}