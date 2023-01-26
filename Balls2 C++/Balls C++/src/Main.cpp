

#include "GL/glew.h"

#include "Object/Object.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include <Graphics/Shader.h>

#include "Object/ObjectHandler.h"
#include "Object/Object.h"
#include "Object/Ball.h"
#include "Object/Mesh.h"
#include "Maths and Physics/Physics.h"
#include "Maths and Physics/Field.h"


int setupOpenGL() {
	if (!glfwInit())
		return 0;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	return 1;
}

int main(void)
{
	
	// Initialize the library.
	if (!setupOpenGL())
		return -1;

	// Create a windowed mode window and its OpenGL context.
	GLFWwindow* window;

	window = glfwCreateWindow(640, 640, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current.
	glfwMakeContextCurrent(window);
	
	//GLEW check
	if (glewInit() == GLEW_OK)
		std::cout << ":)" << std::endl;
	else
		std::cout << ":(" << std::endl;

	//Load shader.
	Shader objShader("src/Graphics/VertexShader.glsl", "src/Graphics/FragmentShader.glsl");
	Shader fluidShader("src/Graphics/fluidVertexShader.glsl", "src/Graphics/fluidFragmentShader.glsl");

	//Set up objects in scene.
	ObjectHandler objects;

	for (int i = 1; i <= 100; i++)
	{
		Ball* ball = new Ball(vec2f((i % 5) * 0.1f - 0.5f, 0), 0.05f, 1);
		Physics* phys = new Physics(1);
		phys->setVelocity(vec2f(1,1));
		
		objects.addObject(ball);
		ball->addPhysics(phys);

	}

	Field<float> f = Field<float>(vec2f(0,0), 100, 100, 0.1f);
	int size = f.size();

	//Ball* ball = new Ball({ 0,0 }, 0.5f, 1.0f);
	//objects.addObject(ball);

	float time_before = 0;
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{

		float time_now = glfwGetTime();
		//Physcis
		objects.updatePhysics(1.0f/60.0f + 0*(time_now - time_before));
		time_before = time_now;

		/* Render here */
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		objShader.use();
		objects.renderObjects(&objShader);

		/* Poll for and process events */
		glfwPollEvents();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}