#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "src/graphics/window.h"
#include "src/math/mathHold.h"
#include "src/graphics/shader/shader.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

const int SHADER_SOURCE_SIZE = 300;
const int WIDTH = 1280;
const int HEIGHT = 720;

int main(int argc, char** argv){
	
	fission::Window window(WIDTH, HEIGHT, "A Little Window", false);
	
	/// <--------- Just a test for my shaders.
	//src/graphics/shader/vertexShader.glsl"
	//"src/graphics/shader/fragmentShader.glsl"
	
	fission::Shader myShader("src/graphics/shader/vertexShader.glsl", "src/graphics/shader/fragmentShader.glsl");
	

	GLfloat vertices[] = {
		// Positions         // Colors
		0.5f, -0.5f, 0.0f, 0.22f, 0.192f, 0.686f,  // Bottom Right
		-0.5f, -0.5f, 0.0f, 0.557f, 0.118f, 0.651f,  // Bottom Left
		0.0f, 0.5f, 0.0f, 0.094f, 0.608f, 0.569f    // Top 
	};

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	/// <--------- End of test for shaders.
	myShader.use();

	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	model = glm::scale(model, glm::vec3(2.0f, 2.0f, 0.0f));
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 2.0f));
	projection = glm::perspective(glm::radians(45.0f), (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
	//perspective(glm::radians(45.0f), (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
	//ortho(0.0f, (float)WIDTH, (float)HEIGHT,0.0f, 0.1f, 100.0f);

	GLint transformLoc = glGetUniformLocation(myShader.f_program, "view");
	GLint projLoc = glGetUniformLocation(myShader.f_program, "projection");
	GLint modelLoc = glGetUniformLocation(myShader.f_program, "model");
	
	
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));


	glm::vec4 color(0.0f, 0.435f, 0.314f, 1.0f);
	double cx[2], cy[2];
	int index = 0;
	
	while (!window.close()){
		window.clear();

		glClearColor(color.x, color.y, color.z, color.w);

		if (window.isKeyPressed(GLFW_KEY_A) || window.isKeyPressed(GLFW_KEY_LEFT)){
			std::cout << "LEFT" << std::endl;
			//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -0.01f));
			model = glm::rotate(model, glm::radians(0.2f), glm::vec3(0.0f, 0.0f, 0.01f));
		}
		if (window.isKeyPressed(GLFW_KEY_S) || window.isKeyPressed(GLFW_KEY_DOWN)){
			view = glm::translate(view, glm::vec3(0.0f, 0.0f, -0.01f));
		}
		if (window.isKeyPressed(GLFW_KEY_W) || window.isKeyPressed(GLFW_KEY_DOWN)){
			view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.01f));
		}
		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)){
			window.getCursorPosition(cx[index], cy[index]);

			if (cx[index] > cx[glm::abs(index - 1)]){
				model = glm::rotate(model, glm::radians(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			}
			else if (cx[index] < cx[glm::abs(index - 1)]){
				model = glm::rotate(model, glm::radians(-1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			}

			if (cy[index] > cy[glm::abs(index - 1)]){
				model = glm::rotate(model, glm::radians(1.0f), glm::vec3(1.0f, 1.0f, 0.0f));
			}
			else if (cy[index] < cy[glm::abs(index - 1)]){
				model = glm::rotate(model, glm::radians(-1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			}

			if (!index){ index = 1; }
			else index = 0;
		}

		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		
		glBindVertexArray(vao);		
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		window.update();
	}

	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &VBO);
	
	return 0;
}
