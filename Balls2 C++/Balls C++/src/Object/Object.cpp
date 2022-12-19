#include "Object.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Mesh.h"
#include "Maths and Physics/Physics.h"

Object::Object(vec2f pos, Mesh* derivedMesh) : pos(pos)
{
	meshPtr = derivedMesh;
	if (!meshPtr->isInitialised()) 
		meshPtr->initialiseMesh();
}

void Object::addPhysics(Physics* phys)
{
	this->phys = phys;
	phys->q = &pos;
	setupPhysics();

}

void Object::setupPhysics()
{
	//Do nothing, to be overridden.
}


//Getters and Setters.

Mesh* Object::getMesh() { return meshPtr; }
float Object::getScale() { return scale; }

void Object::setPos(const vec2f pos){ this->pos.set(pos); }
void Object::setVel(const vec2f vel){
	
	if (phys == nullptr) return;

	this->phys->setVelocity(vel);
}

vec2f* Object::getPosPtr()
{
	return &pos;
}
vec2f Object::getPos()
{
	return pos;
}

Physics* Object::getPhys() { 
	return phys;
}


