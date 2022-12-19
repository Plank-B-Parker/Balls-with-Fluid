#include "Ball.h"
#include <cMath>;
#include "Mesh.h"


float side = std::sqrt(3.0f);
float vertices[9] = {
	-side , -1.0f,
	side, -1.0f,
	0.0f, 2.0f
};

const char* Ball::name = "Ball";

Mesh Ball::ballMesh = Mesh(vertices, 9);



Ball::Ball(vec2f pos, float radius, float mass)
	: Object(pos, &ballMesh), radius(radius), colour(0)
{
	scale = radius;
}

void Ball::setupPhysics()
{
}

const char* Ball::getName()
{
	return name;
}

float Ball::getRad()
{
	return radius;
}

void Ball::setRad(float radius)
{
	this->radius = radius;
}
