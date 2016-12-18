#include "window.h"

namespace fission{
	void windowResize(GLFWwindow* window, int width, int height);

	Window::Window(int width, int height, char* title, bool fullscreen){

		f_width = width;
		f_height = height;
		f_title = title;
		f_fullscreen = fullscreen;

		if (!init()){
			std::cout << "Error: Window did not initialize correctly." << std::endl;
		}

		for (int i = 0; i < GLFW_KEY_LAST; i++){
			f_keys[i] = false;
		}
		for (int i = 0; i < GLFW_MOUSE_BUTTON_LAST; i++){
			f_mouse_buttons[i] = false;
		}

	}


	Window::~Window()
	{
		glfwDestroyWindow(f_window);
		glfwTerminate();
	}

	int Window::getWidth(){ return f_width; }
	int Window::getHeight(){ return f_height;  }

	bool Window::init(){

		if (!glfwInit()){
			std::cout << "Error: glfwInit() failed;" << std::endl;
			return false;
		}

		f_window = glfwCreateWindow(f_width, f_height, f_title, NULL, NULL);

		if (f_fullscreen){
			glfwSetWindowMonitor(f_window, glfwGetPrimaryMonitor(), 0, 0, f_width, f_height, GLFW_REFRESH_RATE);
		}

		if (!f_window){
			std::cout << "Error: Window was not initialized correctly;" << std::endl;
			glfwDestroyWindow(f_window);
			glfwTerminate();
			return false;
		}
		
		glfwMakeContextCurrent(f_window);
		glfwSetWindowUserPointer(f_window, this);
		glfwSetWindowSizeCallback(f_window, windowResize);

		if (glewInit() != GLEW_OK){
			std::cout << "ERROR: GLEW failed to initialize." << std::endl;
			return false;
		}


		glfwSetKeyCallback(f_window, key_callback);
		glfwSetMouseButtonCallback(f_window, mouse_button_callback);
		glfwSetCursorPosCallback(f_window, cursor_position_callback);


		return true;
	}

	void Window::update(){

		glfwPollEvents();
		glfwGetFramebufferSize(f_window, &f_width, &f_height);
		glfwSwapBuffers(f_window);

	}

	void Window::clear(){

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	}

	bool Window::close() {

		return glfwWindowShouldClose(f_window) == 1;

	}

	void windowResize(GLFWwindow* window, int width, int height){
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods){
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->f_keys[key] = action != GLFW_RELEASE;
	}

	void mouse_button_callback(GLFWwindow *window, int button, int action, int mods){
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->f_mouse_buttons[button] = action != GLFW_RELEASE;
	}

	void cursor_position_callback(GLFWwindow *window, double xpos, double ypos){
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->f_mouse_pos_x = xpos;
		win->f_mouse_pos_y = ypos;
	}

	bool Window::isKeyPressed(unsigned int keycode) const{
		if (keycode >= GLFW_KEY_LAST){
			return false;
		}
		return f_keys[keycode];
	}

	bool Window::isMouseButtonPressed(unsigned int keycode) const{
		if (keycode >= GLFW_MOUSE_BUTTON_LAST){
			return false;
		}
		return f_mouse_buttons[keycode];
	}

	void Window::getCursorPosition(double &x, double &y) const{
		x = f_mouse_pos_x;
		y = f_mouse_pos_y;
	}

}