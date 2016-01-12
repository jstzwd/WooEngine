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
		0,-4,0,
		4,0,0,
		-4,0,0
	};
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	Matrice4 ortho = Matrice4::Orthographic(-5, 5, 5, -5, -1, 1);
	Shader myShader("Simple.vert", "Simple.frag");
	myShader.Enable();
	myShader.SetUniform4("pr_matrix", ortho);
	myShader.SetUniform4("ml_matrix", Matrice4::Translate(Vector3(0, 0, 0)));

	myShader.SetUniform2("light_pos", Vector2(0, -1));
	myShader.SetUniform4("colour", Vector4(1, 1, 1, 1));

	
	while (!window.Closed()) {
		window.Clear();
		double x, y;
		window.GetMousePosition(x, y);
		std::cout << x << std::endl;
		std::cout << y << std::endl;
		myShader.SetUniform2("light_pos", Vector2(x*10/800-5, 5-y*10/600));
		glDrawArrays(GL_TRIANGLES, 0, 9);
		window.Update();
	}
	return 0;
}