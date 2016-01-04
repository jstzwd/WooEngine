#include <iostream>
#include "Window.h"
#include "MathWoo.h"
#include "Shader.h"

int main() 
{
	using namespace Woo;
	using namespace Graphics;
	using namespace Math;
	//using namespace Utility;

	Window window("WooEngine",800,600);
	glClearColor(0.f, 0.f, 1.f, 1.f);
	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);
	glGetString(GL_SHADING_LANGUAGE_VERSION);
	Shader myShader("Simple.vert", "Simple.frag");
	while (!window.Closed()) {
		window.Clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.Update();
	}
	return 0;
}