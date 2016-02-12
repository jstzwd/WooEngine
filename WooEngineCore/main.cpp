#include <iostream>
#include "Graphics\Window\Window.h"
#include "Math\MathWoo.h"
#include "Utility\Timer.h"

#include "Graphics\Shaders\Shader.h"
#include "Graphics\Renderers\BasicRenderer.h"
#include "Graphics\Renderers\BatchRenderer.h"
#include "Graphics\Renderables\Renderable.h"
#include "Graphics\Renderables\Sprite.h"
#include "Graphics\Renderables\StaticSprite.h"
#include <time.h>

#include "Graphics\Layers\TileLayer.h" 
#include <FreeImage.h>
#include "Graphics\Shaders\Texture.h"
#include "Graphics\Renderables\Text.h"

int main() 
{
	using namespace Woo;
	using namespace Graphics;
	using namespace Math;
	using namespace Utility;
	//using namespace Utility;

	Window window("WooEngine",1600,1200);
	glClearColor(0.f, 0.f, 0.f, 1.f);
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
#if 0
	GLfloat vertices[] = {
		0,-4,0,
		4,0,0,
		-4,0,0,
		0,4,0
	};
	GLushort indices[] = {
		0,1,2,
		1,2,3
	};
	VertexArray myVA;
	Buffer* myVB = new Buffer(vertices, 16, 3);
	IndexBuffer myIB(indices, 6);
	myVA.AddBuffer(myVB, 0);
#endif
	srand(time(NULL));

	//StaticSprite sprite1(Math::Vector3(-1,1,0), Math::Vector2(2,2),Math::Vector4(1,0,1,1));
	//BasicRenderer2D myRenderer;
	/*
	std::vector<Renderable2D*> sprites;
	BatchRenderer2D myBatchRenderer;

	for (float y = -4.95; y < 5.0f; y += 0.11) {
		for (float x = -4.95; x < 5.0f; x += 0.11) {
			sprites.push_back(new Sprite(Math::Vector3(x, y, 0), Math::Vector2(0.1, 0.1), Math::Vector4(rand() % 1000 / 1000, 1, 0, 1)));
		}
	}
	*/
	
#if 0
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
#endif
	Matrice4 ortho = Matrice4::Orthographic(-5, 5, 5, -5, -1, 1);
	Shader myShader("SampleShaders/Simple.vert", "SampleShaders/Simple.frag");
	myShader.Enable();
	myShader.SetUniform4("pr_matrix", ortho);
	myShader.SetUniform4("ml_matrix", Matrice4::Translate(Vector3(0, 0, 0)));

	myShader.SetUniform2("light_pos", Vector2(0, -1));
	myShader.SetUniform4("colour", Vector4(1, 0, 1, 1));

	Shader* s = new Shader("SampleShaders/Simple.vert", "SampleShaders/Simple.frag");
	
	s->Enable();
	s->SetUniform2("light_pos", Vector2(0, -1));
	TileLayer layer(s);

	Texture* testTextures[] = {
		new Texture("myTexture.png"),
		new Texture("myTexture2.png"),
		new Texture("myTexture3.png")
	};

	for (float y = -4.95; y < 5.0f; y += 0.33) {
		for (float x = -4.95; x < 5.0f; x += 0.33) {
			if (rand() % 4 == 0) 
			{
				layer.AddRenderable2D(new Sprite(Math::Vector3(x, y, 0), Math::Vector2(0.3, 0.3), Math::Vector4(rand() % 1000 / 1000, 1, 0, 1)));
			}
			else
			{
				int i = rand() % 3;
				layer.AddRenderable2D(new Sprite(Math::Vector3(x, y, 0), Math::Vector2(0.3, 0.3), testTextures[i]));
				
			}

		}
	}

	GLint textureNumbers[] = { 0,1,2,3,4,5,6,7,8,9 };
	s->Enable();
	s->SetUniform1("myTextures", 10, textureNumbers);
	s->SetUniform4("pr_matrix", ortho);

	Text myText("WooEngine", Math::Vector3(0, 0, 0), Math::Vector4(1, 1, 1, 1));
	layer.AddRenderable2D(&myText);
#if 1
	

#endif
	Timer myTimer;
	double previousTime=0;
	unsigned int fps=0;
	while (!window.Closed()) {
		window.Clear();
		double x, y;
		window.GetMousePosition(x, y);
		myShader.SetUniform2("light_pos", Vector2(x*10/1600-5, 5-y*10/1200));

#if 0
		myVA.Bind();
		myIB.Bind();
		//glDrawArrays(GL_TRIANGLES, 0, 12);
		glDrawElements(GL_TRIANGLES, myIB.GetCount(), GL_UNSIGNED_SHORT, 0);
		myIB.UnBind();
		myVA.UnBind();
#endif

#if 0
		myBatchRenderer.Begin();
		for (int i = 0; i < sprites.size(); i++) {
			myBatchRenderer.Submit(sprites[i]);
		}
		
		myBatchRenderer.End();
		myBatchRenderer.Flush();
#endif
		layer.RenderLayer();
		window.Update();
		fps++;
		if (myTimer.ElapsedTime() - previousTime>1) {
			printf("%d fps\n", fps);
			previousTime += 1;
			fps = 0;
		}
		
		
	}
	for (int i = 0; i < 3; i++) {
		delete testTextures[i];
	}
	return 0;
}