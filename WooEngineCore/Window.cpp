#include "window.h"

namespace Woo {
	namespace Graphics {
		//void WindowResize(GLFWwindow* window, int width, int height);
		bool Window::m_keys[MAX_KEYS];
		bool Window::m_mouseButtons[MAX_BUTTONS];
		double Window::m_mouseX;
		double Window::m_mouseY;
		Window::Window(const char* title, int width, int height) {
			m_title = title;
			m_width = width;
			m_height = height;
			if (!Init()) {
				glfwTerminate();
			}
		}

		Window::~Window() {
			glfwTerminate();
		}

		void Window::Update(){
			GLenum myError = glGetError();
			if (myError != GL_NO_ERROR) {
				std::cout << "OpenGL Error: "<< myError << std::endl;
			}
			glfwPollEvents();
			//glfwGetFramebufferSize(m_window, &m_width, &m_height);
			//glViewport(0, 0, m_width, m_height);
			glfwSwapBuffers(m_window);

		}
		bool Window::Init() {
			if (!glfwInit()) {
				std::cout << "Failed to Initiatialize GLFW!" << std::endl;
				return false;
			}
			m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
			if (!m_window) {
				glfwTerminate();
				std::cout << "Window generation failed!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_window);
			glfwSetWindowUserPointer(m_window, this);
			glfwSetWindowSizeCallback(m_window, WindowResize);
			glfwSetKeyCallback(m_window, KeyCallBack);
			glfwSetMouseButtonCallback(m_window, MouseButtonCallBack);
			glfwSetCursorPosCallback(m_window, MousePositionCallback);
			glfwSwapInterval(0.0);
			if (glewInit() != GLEW_OK) {
				std::cout << "Failed to Initialize GLEW!" << std::endl;
				return false;
			}
			std::cout << glGetString(GL_VERSION) << std::endl;
			return true;
		}

		bool Window::Closed() const {
			return glfwWindowShouldClose(m_window)==1;
		}
		void Window::Clear() {
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		}
		void Window::WindowResize(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}
		void Window::KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mode) {
			m_keys[key] = (action != GLFW_RELEASE);
			//Window* thisWindow=(Window*)glfwGetWindowUserPointer(window);
			//thisWindow->m_keys[key] = (action != GLFW_RELEASE);
		}
		void Window::MouseButtonCallBack(GLFWwindow* window, int button, int action, int mods) {
			m_mouseButtons[button] = (action != GLFW_RELEASE);
		}
		void Window::MousePositionCallback(GLFWwindow* window, double xpos, double ypos) {
			m_mouseX = xpos;
			m_mouseY = ypos;
		}
		bool Window::KeyPressed(unsigned int keyCode) {
			if (keyCode >= MAX_KEYS) {
				return false;
			}
			return m_keys[keyCode];
		}
		bool Window::MouseButtonPressed(unsigned int buttonCode) {
			if (buttonCode >= MAX_BUTTONS) {
				return false;
			}
			return m_mouseButtons[buttonCode];
		}
		void Window::GetMousePosition(double& x, double& y) {
			x = m_mouseX;
			y = m_mouseY;
		}
	}
}