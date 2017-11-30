
#include "Application.h"
#include <iostream>
#include <vector>

#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
//#include "GL/freeglut.h"

#include "ShaderFuncs.h"

GLfloat vertexPositions[] = {
	0.75f, 0.75f, 0.0f, 1.0f,  //a
	-0.75f, -0.75f, 0.0f, 1.0f, //c
	0.75f, -0.75f, 0.0f, 1.0f, //b
	/*-----------------------------------*/
	0.75f, 0.75f, 0.0f, 1.0f,  //a
	-0.75f, 0.75f, 0.0f, 1.0f, //d	
	-0.75f, -0.75f, 0.0f, 1.0f, //c
};


GLfloat vertexColors[] = {
	0.0, 0.5, 0.5,1.0,
	0.0, 0.5, 0.5,1.0,
	1.0, 0.0, 1.5, 1.0,

	/*----------------------*/
	0.0, 0.5, 0.5,1.0,
	1.0, 0.0, 1.5, 1.0,
	0.5, 0.5, 0.5, 1.0,
};



const std::string strVertexShader(
	"#version 430 core\n"

	"layout (location = 0) in vec4 vPosition;"
	"layout (location = 1) in vec4 vColor;"

	"out vec4 color;"
	"uniform float angle;"

	"void main()"
	"{"
	"	vec4 newPos = vPosition;"
	"	newPos.x = cos(angle) * newPos.x;"
	"	color = vColor;"

	"   gl_Position = newPos;"
	"}"
	);


const std::string strFragmentShader(
	"#version 430 core\n"

	"out vec4 fragmentColor;"
	"in vec4 color;"

	"void main()"
	"{"
	"    fragmentColor = color;"
	"}"
	);

Application::Application() : angle(0)
{}

Application::~Application() 
{}

void Application::setup()
{
	std::string strVertexShader = loadTextFile("Shaders\\vertex.vs");
		std::string strFragmentShader = loadTextFile("Shaders\\fragment.fs");

	InitializeProgram(triangle.shader, strVertexShader, strFragmentShader);
	angleID = glGetUniformLocation(triangle.shader, "angle");
	triangle.numVertex = 6;
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

void Application::update()
{
	angle += 0.001f;
}


void Application::display()
{
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//Seleccionamos los shaders a usar
	glUseProgram(triangle.shader);	
	glUniform1f(angleID, angle);
	
	//activamos el vertex array object y dibujamos
	glBindVertexArray(triangle.vao);

	glDrawArrays(GL_TRIANGLES, 0, triangle.numVertex);
}

void Application::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}
