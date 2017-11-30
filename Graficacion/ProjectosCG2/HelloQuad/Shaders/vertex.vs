	#version 430 core

	layout (location = 0) in vec4 vPosition;
	layout (location = 1) in vec4 vColor;

	out vec4 color;
	uniform float angle;

	void main()
	{
		vec4 newPos = vPosition;
		newPos.x = cos(angle) * newPos.x;
		color = vColor;

	   gl_Position = newPos;
	}