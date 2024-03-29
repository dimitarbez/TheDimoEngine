#include <iostream>
#include "GL/glew.h"
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"
#undef main

#define WIDTH 800
#define HEIGHT 600

int main()
{
	Display display(800, 600, "Memes");
	

	Vertex vertices[] = {	Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
							Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
							Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0))};

	unsigned int indices[] = { 0, 1, 2 };

	Shader shader("./res/basicShader");
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
	Mesh mesh2("./res/monkey3.obj");
	Texture texture("./res/bricks.jpg");
	Camera camera(glm::vec3(0, 0, -4), 70.f, (float)WIDTH/(float)HEIGHT, 0.01f, 1000.f);
	Transform transform;

	float counter = 0.0f;

	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.1f, 0.3f, 1.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.GetPosition().x = sinf(counter);
		transform.GetPosition().z = cosf(counter);
		transform.GetRotation().z = cosf(counter);
		transform.GetRotation().x = counter*3;

		shader.Bind();
		texture.Bind(0);
		shader.Update(transform, camera);
		mesh.Draw();
		mesh2.Draw();

		display.Update();
		counter += 0.01f;
	}
	return 0;
}
