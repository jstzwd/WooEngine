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
	/*
	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);
	glGetString(GL_SHADING_LANGUAGE_VERSION);
	*/
	/*
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5, 0.5, 0);
	glVertex3f(-0.5, 0, 0);
	glVertex3f(0, -0.5, 0);
	glEnd();
	*/
	GLfloat vertices[] = {
		0,-1,0,
		1,0,0,
		0,0,0
	};
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	Shader myShader("Simple.vert", "Simple.frag");
	myShader.Enable();
	
	while (!window.Closed()) {
		window.Clear();
		glDrawArrays(GL_TRIANGLES, 0, 9);
		window.Update();
	}
	return 0;
}