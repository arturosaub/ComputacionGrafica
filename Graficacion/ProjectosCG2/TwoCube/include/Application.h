#pragma once

#include <iostream>
#include "Object3D.h"
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"


class Application {
public:
	Application();
	~Application();

	void setup();
	void keyboard(int , int , int , int );
	void update();
	void display();
	void reshape(int w, int h);


	GLFWwindow* window;



private:	
	GLuint angleID, transformID;
	Object3D triangle;

	glm::mat4 camera;
	glm::mat4 transform;
	glm::vec3 eye, target, angles;
};

