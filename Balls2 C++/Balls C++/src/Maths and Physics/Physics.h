#pragma once
#include "vec2f.h"
#include "Object/Object.h"
#include <vector>

//class PhysicsComponent;
class Physics
{

	friend struct CollisionPair;
	friend class ObjectHandler;	//Slowly remove the need to make this class a friend.
	friend class Object; //Maybe add methods in physics that Object class can access.

private:
	vec2f* q = nullptr;		//Maybe have: const vec2f& q; and set it to object's pos.
	vec2f p = 0;
	vec2f F = 0;
	float m = 1.0f;
	float e = 1.0f; //Coeff of Restitution.

	//List of contact points.
	//...

	//List of Constraints?
	//...

	//List of forces components
	//std::vector<PhysicsComponent> physicsComponents;
	//...

	void computeForces(); //Find a way for Physics handler to handle this.
	void updatePos(float dt);
	void updateMomentum(float dt);

public:
	Physics(float mass = 1);

	//Adds component to physics, which adds another force to compute.
	//void addComponent(PhysicsComponent C);


	//Getters and Setters
	vec2f getPos();
	const vec2f* getPosPtr();

	vec2f getVelocity();
	const vec2f* getMomentumPtr();

	vec2f getNetForce();
	const vec2f* getNetForcePtr();

	float getMass();
	float getCoeffRest();

	void setMomentum(vec2f m);
	void setVelocity(vec2f v);
	void setNetForce(vec2f f);

	void setMomentum(float mx, float my);
	void setNetForce(float fx, float fy);

	void setMass(float m);
	void setCoeffRest(float e);

};

//std::vector<Physics*> allPhysObjs;

//void updateVerlet(std::vector<Physics*> physObjs, float dt)
//{
//	for (Physics* physPtr : physObjs) { physPtr->computeForces(); }
//}







