#pragma once
#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace fission{
	class Window
	{
	private:
		friend struct GLFWwindow;

		int f_width;
		int f_height;
		const char* f_title;
		bool f_fullscreen;
		GLFWwindow* f_window;

		bool f_keys[GLFW_KEY_LAST];
		bool f_mouse_buttons[GLFW_MOUSE_BUTTON_LAST];
		double f_mouse_pos_x, f_mouse_pos_y;

	public:
		Window(int width, int height, char* title, bool fullscreen);
		~Window();

		int getWidth();
		int getHeight();

		bool init();
		void update();
		bool close();
		void clear();

		bool isKeyPressed(unsigned int keycode)const;
		bool isMouseButtonPressed(unsigned int button)const;
		void getCursorPosition(double &x, double &y)const;

		friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
		friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
		friend void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
	};
}