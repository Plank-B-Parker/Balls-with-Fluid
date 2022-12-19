#pragma once
#include "Object.h"

struct Mesh;
class Ball : public Object
{
private:
	float radius;
	int colour;
	static Mesh ballMesh;
	const static char* name;

	void setupPhysics() override;

public:
	Ball(vec2f pos, float radius = 1, float mass = 1);

	float getRad();

	void setRad(float radius);
	const char* getName() override;
};

