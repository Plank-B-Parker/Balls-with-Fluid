#include "Mesh.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Maths and Physics/vec2f.h"

Mesh::Mesh(float vertices[], int arrSize) {
	numOfVertices = arrSize;
	for (int i = 0; i <= arrSize; i++)
	{
		this->vertices[i] = vertices[i];
	}	
}

//Mesh is initialised in Object class.
void Mesh::initialiseMesh()
{
	int arrSize = numOfVertices;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, arrSize * sizeof(float), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	initialised = true;
}

vec2f Mesh::getVertex(int index) const{
	return vec2f(vertices[2 * index], vertices[2 * index + 1]);
}

unsigned int Mesh::getVAO() const{
	return VAO;
}

unsigned int Mesh::getVBO() const {
	return VBO;
}

bool Mesh::isInitialised() const {
	return initialised;
}