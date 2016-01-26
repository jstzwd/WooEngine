#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Woo {
	namespace Graphics {
#define MAX_KEYS 1024
#define MAX_BUTTONS 32
		class Window {
		private:
			const char* m_title;
			int m_width, m_height;
			GLFWwindow* m_window;
			bool m_closed;
			static bool m_keys[MAX_KEYS];
			static bool m_mouseButtons[MAX_BUTTONS];
			static double m_mouseX, m_mouseY;
		public:
			Window(const char* title, int width, int height);
			~Window();
			void Update();
			bool Closed() const;
			void Clear();
			inline int GetWidth() const { return m_width; };
			inline int GetHeight() const { return m_height; };
			static bool KeyPressed(unsigned int keyCode);
			static bool MouseButtonPressed(unsigned int buttonCode);
			static void GetMousePosition(double& x, double& y);

		private:
			bool Init();
			static void WindowResize(GLFWwindow* window, int width, int height);
			static void KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
			static void MouseButtonCallBack(GLFWwindow* window, int button, int action, int mods);
			static void MousePositionCallback(GLFWwindow* window, double xpos, double ypos);
		};
	}
}