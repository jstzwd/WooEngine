#include <iostream>
#include "Window.h"

int main() 
{
	using namespace Woo;
	using namespace Graphics;

	Window window("WooEngine",800,600);
	glClearColor(0.f, 0.f, 1.f, 1.f);
	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);
	while (!window.Closed()) {
		window.Clear();
		if (window.KeyPressed(GLFW_KEY_0)) {
			std::cout << "Pressed 0!" << std::endl;
		}
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#if 0
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, 0.f);
		glVertex2f(0.5f, 1.f);
		glVertex2f(0.f, -0.5f);
		glEnd();
#endif
		window.Update();
	}
	return 0;
}