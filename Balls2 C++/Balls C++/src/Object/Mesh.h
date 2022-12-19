#pragma once 

struct vec2f;

//Make this abstract class? So that different mesh types can have different methods.
//e.g getFurthestVertex() for Ball or Box.
struct Mesh
{
	Mesh(float vertices[], int arrSize);

	vec2f getVertex(int index) const;
	vec2f getFurthestVertex(vec2f direction) const;	//optimisation: store vertices in list, 
												//according to direction. Like pixel array.
												//Project points out to a sphere and represesnt
												//like a pixel array? [x,y] -> [theta (longitude), phi (lattitude)] 
	vec2f getVertex() const;

	void initialiseMesh();
	bool isInitialised() const;


	unsigned int getVAO() const;
	unsigned int getVBO() const;
private:
	
	bool initialised = false;

	unsigned int VAO = 1;
	unsigned int VBO = 1;

	float numOfVertices;
	float vertices[];	//Array with undefined length seems to only work if it's the last member.
						//Probably because if it wasn't then it doesn't know how much of a gap to
						//leave for the rest of the data after the array.
};

