#include "Physics.h"

Physics::Physics(float mass)
{
	m = mass;
}

void Physics::updatePos(float dt)
{
	*q += (1 / m) * p * dt;
}

void Physics::updateMomentum(float dt)
{
	p += F * dt;
}

void Physics::computeForces()
{
	F = vec2f(0,-0*9.81);
	//Implement forces.

	if (q->x > 1) {
		q->x = 1;
		p.x = -p.x;
	}
	if (q->x < -1) {
		q->x = -1;
		p.x = -p.x;
	}
	if (q->y > 1) {
		q->y = 1;
		p.y = -p.y;
	}
	if (q->y < -1) {
		q->y = -1;
		p.y = -p.y;
	}
}


//Getters and Setters.
void Physics::setMomentum(vec2f momentum){ p = momentum; }
void Physics::setVelocity(vec2f v){ p = m * v; }

void Physics::setNetForce(vec2f f){ F = f; }

void Physics::setMass(float mass){ m = mass;}
void Physics::setCoeffRest(float e){ this->e = e; }

vec2f Physics::getPos(){ return *q; }
const vec2f* Physics::getPosPtr(){ return q; }

vec2f Physics::getVelocity(){ return p*(1/m); }
const vec2f* Physics::getMomentumPtr(){ return &p; }

vec2f Physics::getNetForce(){ return F; }
const vec2f* Physics::getNetForcePtr(){ return &F; }

float Physics::getMass(){ return m; }
float Physics::getCoeffRest(){ return e; }