
#include "Application.h"
#include <iostream>
#include <vector>
#include "glm/gtc/matrix_transform.hpp"
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glm/gtc/type_ptr.hpp"
#include "ShaderFuncs.h"


GLfloat vertexPositions[] = {
	 0.75f,   0.75f, 0.75f, 1.0f,//a
	-0.75f,  -0.75f, 0.75f, 1.0f,//c
	 0.75f,  -0.75f, 0.75f, 1.0f,//b
	 0.75f,   0.75f, 0.75f, 1.0f,//a
	-0.75f,   0.75f, 0.75f, 1.0f,//d
	-0.75f,  -0.75f, 0.75f, 1.0f,//c
	//Cara 1
	// -------------------- 
	//Cara 2

	  0.75f, 0.75f, -0.75f, 1.0f,//e
	 -0.75f, 0.75f,  0.75f, 1.0f,//d
	  0.75f, 0.75f,  0.75f, 1.0f,//a
	  0.75f, 0.75f, -0.75f, 1.0f,//e
	 -0.75f, 0.75f, -0.75f, 1.0f,//f
	 -0.75f, 0.75f,  0.75f, 1.0f,//d
	//Cara 2
	// -------------------- 
	//Cara 3

	-0.75f, 0.75f,  0.75f, 1.0f,//d
	-0.75f,-0.75f, -0.75f, 1.0f,//g
	-0.75f,-0.75f,  0.75f, 1.0f,//c
	-0.75f, 0.75f,  0.75f, 1.0f,//d
	-0.75f, 0.75f, -0.75f, 1.0f,//f
	-0.75f,-0.75f, -0.75f, 1.0f,//g
	//Cara 3
	// -------------------- 
	//Cara 4

	0.75f, 0.75f, -0.75f, 1.0f,//e
	0.75f,-0.75f,  0.75f, 1.0f,//b
	0.75f,-0.75f, -0.75f, 1.0f,//h
	0.75f, 0.75f, -0.75f, 1.0f,//e
	0.75f, 0.75f,  0.75f, 1.0f,//a
	0.75f,-0.75f,  0.75f, 1.0f,//b
	//Cara 4
	// -------------------- 
	//Cara 5

	 0.75f,-0.75f,  0.75f, 1.0f,//b
	-0.75f,-0.75f, -0.75f, 1.0f,//g
	 0.75f,-0.75f, -0.75f, 1.0f,//h
	 0.75f,-0.75f,  0.75f, 1.0f,//b
	-0.75f,-0.75f,  0.75f, 1.0f,//c
	-0.75f,-0.75f, -0.75f, 1.0f,//g
	//Cara 5
	// -------------------- 
	//Cara 6

	 0.75f,-0.75f, -0.75f, 1.0f,//h
	-0.75f, 0.75f, -0.75f, 1.0f,//f
	 0.75f, 0.75f, -0.75f, 1.0f,//e
	 0.75f,-0.75f, -0.75f, 1.0f,//h
	-0.75f,-0.75f, -0.75f, 1.0f,//g
	-0.75f, 0.75f, -0.75f, 1.0f,//f


};


GLfloat vertexColors[] = {
	1.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 1.0,
	//Red
	//Cara 1
	// -------------------- 
	//Cara 2
	0.0, 1.0, 0.0, 1.0,
	0.0, 1.0, 0.0, 1.0,
	0.0, 1.0, 0.0, 1.0,
	0.0, 1.0, 0.0, 1.0,
	0.0, 1.0, 0.0, 1.0,
	0.0, 1.0, 0.0, 1.0,
	//Green
	//Cara 2
	// -------------------- 
	//Cara 3
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	//Blue
	//Cara 3
	// -------------------- 
	//Cara 4

	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,
	//white
	//Cara 4
	// -------------------- 
	//Cara 5

	1.0, 1.0, 0.0, 1.0,
	1.0, 1.0, 0.0, 1.0,
	1.0, 1.0, 0.0, 1.0,
	1.0, 1.0, 0.0, 1.0,
	1.0, 1.0, 0.0, 1.0,
	1.0, 1.0, 0.0, 1.0,
	//Yellow
	//Cara 4
	// -------------------- 
	//Cara 5
	1.0, 0.50, 0.20, 1.0,
	1.0, 0.50, 0.20, 1.0,
	1.0, 0.50, 0.20, 1.0,
	1.0, 0.50, 0.20, 1.0,
	1.0, 0.50, 0.20, 1.0,
	1.0, 0.50, 0.20, 1.0,
	//Orange
};





Application::Application() : eye(0.0f,0.0f,5.0f),
							 target(0.0f,0.0f,0.0f),
							 transform(glm::mat4(1.0f)),
							 angles(1.0f,0.0f,0.0f)
{}

Application::~Application() 
{}


void Application::update()
{
	angles.x +=0.05f;
	angles.y +=0.05f;
	camera = glm::lookAt(eye,target,glm::vec3(0.0f,1.0f,0.0f));
	transform = glm::rotate(glm::mat4(1.0f), glm::radians(angles.x), glm::vec3(1.0f, 0.0f, 0.0f));
	transform = glm::rotate(transform, glm::radians(angles.y), glm::vec3(0.0f, 1.0f, 0.0f));
	transform = glm::perspective(45.0f,1024.0f/768.0f,.1f,10.0f) *  
				camera * transform;
}

void Application::keyboard(int key, int scancode, int actions, int mods)
{
	if (actions == GLFW_RELEASE)
	{
		switch (key)
		{
		case GLFW_KEY_ESCAPE: glfwSetWindowShouldClose(window, GLFW_TRUE);

			break;

		case GLFW_KEY_Y: ++angles.y;
			break;

		}
	}

}


void Application::setup()
{
	std::string strVertexShader = loadTextFile("Shaders\\vertex.vs");
	std::string strFragmentShader = loadTextFile("Shaders\\Fragment.fs");
	InitializeProgram(triangle.shader, strVertexShader, strFragmentShader);
	transformID = glGetUniformLocation(triangle.shader, "transform");
	angleID = glGetUniformLocation(triangle.shader, "angle");
	triangle.numVertex = 36; //Numero de Vertices
	glGenVertexArrays(1, &triangle.vao);
	glBindVertexArray(triangle.vao);
	glGenBuffers(1, &triangle.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, triangle.vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions)+sizeof(vertexColors), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0/*offset*/, sizeof(vertexPositions), vertexPositions);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexPositions), sizeof(vertexColors), vertexColors);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(vertexPositions));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}




void Application::display()
{
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Seleccionamos los shaders a usar
	glUseProgram(triangle.shader);	
	glUniformMatrix4fv(transformID, 1, GL_FALSE, glm::value_ptr(transform));
	
	//activamos el vertex array object y dibujamos
	glBindVertexArray(triangle.vao);

	glDrawArrays(GL_TRIANGLES, 0, triangle.numVertex);
}

void Application::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}
