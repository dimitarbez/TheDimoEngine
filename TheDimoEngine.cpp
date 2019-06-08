#include <iostream>
#include "GL/glew.h"
#include "Display.h"

int main()
{
	Display display(1280, 720, "Memes");
	
	while (!display.IsClosed())
	{
		glClearColor(0.0f, 0.3f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		display.Update();
	}
}
