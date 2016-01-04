#include <iostream>
#include "Window.h"
#include "MathWoo.h"
#include "FileUtility.h"

int main() 
{
	using namespace Woo;
	using namespace Graphics;
	using namespace Math;
	using namespace Utility;

	std::string test=ReadFile("main.cpp");
	std::cout<<test<<std::endl;
	Window window("WooEngine",800,600);
	glClearColor(0.f, 0.f, 1.f, 1.f);
	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);
	Vector2 v1(0,8);
	Vector2 v2(-1, 9);
	Vector3 v3(4,6,7);
	Vector4 v4 = Vector4::zero * 2;
	
	Matrice4 myMatrice(1.0f);
	std::cout << myMatrice.columns[3] << std::endl;
	while (!window.Closed()) {
		window.Clear();
		if (window.KeyPressed(GLFW_KEY_0)) {
			std::cout << "Pressed 0!" << std::endl;
		}
		std::cout << v2+v1 << std::endl;
		std::cout << (v3/2) << std::endl;
		std::cout << v4*1.6f << std::endl;
		std::cout << (v4 == Vector4::zero) << std::endl;
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