#include "shader.h"

namespace fission{
	
	Shader::Shader(char* vertexShaderLocation, char* fragmentShaderLocation){
		readShader(vertexShaderLocation, f_vertexSource);
		readShader(fragmentShaderLocation, f_fragmentSource);

		compileShader(f_vertexShader, vertexShader, f_vertexSource);
		compileShader(f_fragmentShader, fragmentShader, f_fragmentSource);

		createProgram(f_program, f_vertexShader, f_fragmentShader);

	}

	Shader::~Shader(){}

	void Shader::use(){ glUseProgram(f_program); }

	void Shader::readShader(char* shaderLocation, char* &shaderSource){
		//Creates a file stream and opens a file.
		std::ifstream iFile(shaderLocation);

		if (iFile.is_open()){
			
			//Opens file and seeks the size.
			iFile.seekg(0, iFile.end);
			int size = iFile.tellg();
			iFile.seekg(0, iFile.beg);

			//cCreates the size of the array with the given size.
			shaderSource = new char[size];

			//Sets every character to root out bugs on different machines.
			for (int i = 0; i < size; i++){
				shaderSource[i] = ' ';
			}

			//Writes the array from the file.
			for (int i = 0; i < size; i++){
				iFile.get(shaderSource[i]);
			}

			
		}
		else{
			//Just error checking.
			std::cout << "ERROR. Wrong file Path... " << shaderLocation << std::endl;
		}

		//Close?
		iFile.close();
		
	}

	void Shader::compileShader(GLuint& shader, ShaderType type, char* &shaderSource){
		if (type == vertexShader){
			shader = glCreateShader(GL_VERTEX_SHADER);
		}
		else if (type == fragmentShader){
			shader = glCreateShader(GL_FRAGMENT_SHADER);
		}
		else{
			std::cout << "SHADER ERROR: No shader type was found." << std::endl;
		}

		glShaderSource(shader, 1, &shaderSource, NULL);
		glCompileShader(shader);
		if (!Shader::checkShaderError(shader, type)){
			std::cout << "No error on shader " << type << " found" << std::endl;
		}
	}

	void Shader::createProgram(GLuint& shaderProgram, GLuint& vertexShader, GLuint& fragmentShader){
		/*
			DON'T FORGET TO CALL:
			glUseProgram(shaderProgram);
			BEFORE USING THE SHADER PROGRAM.
		*/
		shaderProgram = glCreateProgram();

		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		//ErrorChecking: Creating a shader program.

		if (!checkShaderProgramError(shaderProgram)){
			std::cout << "No error on shader program." << std::endl;
		}

		//No need for the shaders anymore.
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	bool Shader::checkShaderError(GLuint& shader, ShaderType type){
		const int SIZE = 300;
		GLint success;
		GLchar infoLog[SIZE];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if (!success){
			glGetShaderInfoLog(shader, SIZE, NULL, infoLog);
			std::cout << "ERROR - Compilation Failed in " << type << infoLog << std::endl;
			return true;
		}
		else{
			return false;
		}
	}

	bool Shader::checkShaderProgramError(GLuint& program){
		const int SIZE = 300;
		GLint success;
		GLchar infoLog[SIZE];
		glGetProgramiv(program, GL_COMPILE_STATUS, &success);

		if (!success){
			glGetProgramInfoLog(program, SIZE, NULL, infoLog);
			std::cout << "ERROR - Shader Program failed to link. " << infoLog << std::endl;
			return true;
		}
		else{
			return false;
		}
	}
	
}