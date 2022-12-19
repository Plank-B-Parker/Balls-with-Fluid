#pragma once
#include "../Maths and Physics/vec2f.h"
#include "ObjectHandler.h"

class Physics;
struct Mesh;

class Object {

	friend class ObjectHandler;

protected:

	vec2f pos;
	float scale = 1.0f; //Transformation Matrix later on.

	Physics* phys = nullptr;
	Mesh* meshPtr;

	Object(vec2f pos, Mesh* mesh);
	
	virtual void setupPhysics() = 0;

public:

	void addPhysics(Physics* phys);


	//Getters and Setters.
	void setPos(vec2f pos);
	void setVel(vec2f vel);

	vec2f* getPosPtr();
	vec2f getPos();

	Physics* getPhys();

	float getScale();
	Mesh* getMesh();

	virtual const char* getName() = 0;
};

