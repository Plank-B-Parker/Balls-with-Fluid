#pragma once

#include "vec2f.h"
#include <vector>
#include <unordered_map>

class Object;
class Ball;

struct ContactPoint {
	vec2f disp;
	bool penetrating;

	vec2f vA;	//Use pointer to vertex in Object?
	vec2f vB;

	ContactPoint(vec2f disp, bool penetrating, vec2f vA, vec2f vB) : disp(disp), penetrating(penetrating), vA(vA), vB(vB), null(false) {};
	ContactPoint() : null(true) {};

	operator bool() {
		return !null;
	}

	private:
		bool null = true;
};

struct CollisionPair {

	bool null = true;
	bool colliding = false;
	Object *A, *B;	
	
	vec2f dir = 0;	//Direction of penetration.
	float penDepth = NAN;	//Penetration depth. Negative if resolved.

	vec2f relVel;	//Relative velocity.

	int contactIndex = 0;
	static const int MAX_CONTACTS = 4;
	ContactPoint contPoints[MAX_CONTACTS];

	CollisionPair();	//Empty collision.
	CollisionPair(Object* A, Object* B);	

	void addContactPoint(ContactPoint point);
	ContactPoint ejectContactPoint();

	operator bool() { return null; };

};

struct CollisionGroup {
	std::vector<Object*> group;
	float sensitivity = 0.1f;		//Maximum distance between objects tracked.


	void filterCollisions();	//Broad Phase.
	void detectCollisions();	//Narrow Phase.
	void resolveCollisions();

	void addObject(Object* obj);
	void removeObject(Object* obj);
	void removeObject(int index);

private:
	std::vector<CollisionPair> pairs;	//Pairs of valid and invalid collisions.
	std::unordered_map<Object*, std::vector<CollisionPair> > collisionMap;	//Every collision each object is part of.

	CollisionPair detectBallvsBall(Ball* ballA, Ball* ballB);
	void resolveColBallvsBall(CollisionPair pair);
	void resolveCol(CollisionPair P);

	void addCollision(CollisionPair pair);
	void removeCollision();
};

