#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <GL/glew.h>

namespace fission{
	
	enum ShaderType{
		vertexShader = 1,
		fragmentShader = 2
	};

	class Shader{
	private:

		GLuint f_vertexShader;
		GLuint f_fragmentShader;

		char* f_vertexSource;
		char* f_fragmentSource;
	public:

		GLuint f_program;

		Shader(char* vertexShaderLocation, char* fragmentShaderLocation);
		~Shader();

		void setShader(ShaderType type, char* shaderLocation);
		void use();

		static void readShader(char* shaderLocation, char* &shaderSource);

		static void compileShader(GLuint& shader, ShaderType type, char* &shaderSource);
		static void createProgram(GLuint& shaderProgram, GLuint& vertexShader, GLuint& fragmentShader);
		static bool checkShaderError(GLuint& shader, ShaderType type);
		static bool checkShaderProgramError(GLuint& shader);

	};

	
}