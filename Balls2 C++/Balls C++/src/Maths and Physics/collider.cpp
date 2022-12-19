#include "collider.h"
#include "Object/Object.h"
#include "Object/Ball.h"
#include "Physics.h"

/////////////////////////Collision Pair//////////////////////////////

CollisionPair::CollisionPair() {
	A = nullptr;
	B = nullptr;
}

CollisionPair::CollisionPair(Object* A, Object* B) {
	this->A = A;
	this->B = B;
	relVel = A->getPhys()->getVelocity() - B->getPhys()->getVelocity();
	null = false;
}

void CollisionPair::addContactPoint(ContactPoint point) {
	if (!point) return;	//null contact

	//Change it so that it picks the best contact points for resolution (Maximise area).
	contPoints[contactIndex % MAX_CONTACTS] = point; //Index wraps around: Oldest entry gets replaced when full. 
	contactIndex++;

	if (point.penetrating) colliding = true;
}

ContactPoint CollisionPair::ejectContactPoint() {
	//Horrible to read. Probably wont understand in the future. Oh well... 
	bool stillPenetrating = !colliding;	//Check if contact point is still penetrating if it's colliding.
	for (int i = contactIndex + 1; i < contactIndex + MAX_CONTACTS && !stillPenetrating; i++) {
		if (contPoints[i % MAX_CONTACTS].penetrating)
			stillPenetrating = true;
	}
	
	return contPoints[contactIndex--];
}

//Figure out dir and penetration depth when contact points are added?


/////////////////////////Collision Group//////////////////////////////

void CollisionGroup::filterCollisions() {

	for (Object* object : group) {
		
	}
}

void CollisionGroup::addObject(Object* obj) {
	for (Object* object : group)
		if (obj == object) return;

	group.push_back(obj);
}

void CollisionGroup::removeObject(Object* obj) {
	int i = 0;
	for (Object* object : group)
		if (obj == object) {
			group.erase(group.begin() + i); 
	
			return;
		}
		else i++;
}

void CollisionGroup::removeObject(int index) {
	group.erase(group.begin() + index);
}


CollisionPair CollisionGroup::detectBallvsBall(Ball* ballA, Ball* ballB) {
	//Invalid Collision.
	if (ballB == ballA || ballA == nullptr || ballB == nullptr)
		return CollisionPair();


	vec2f disp = ballA->getPos() - ballB->getPos();
	float rA = ballA->getRad();
	float rB = ballB->getRad();
	
	//Invalid Collision.
	if (disp.lengthSq() > (rA + rB)*(rA + rB))
		return CollisionPair();

	return CollisionPair(ballA, ballB);

}

void CollisionGroup::addCollision(CollisionPair pair) {

	if (!pair.colliding) return;
}
