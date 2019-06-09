#include <iostream>
#include "GL/glew.h"
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#undef main

int main()
{
	Display display(800, 600, "Memes");
	
	Shader shader("./res/basicShader");

	Vertex vertices[] = {	Vertex(glm::vec3(-0.5, -0.5, 0)),
							Vertex(glm::vec3(0, 0.5, 0)), 
							Vertex(glm::vec3(0.5, -0.5, 0))};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	while (!display.IsClosed())
	{
		glClearColor(0.0f, 0.3f, 0.2f, 1.0f);
		shader.Bind();

		mesh.Draw();

		display.Update();
	}
	return 0;
}
