#include "Object.h"
#include "ObjectHandler.h"
#include "Ball.h"
#include "Mesh.h"

#include "Graphics/Shader.h"

#include <algorithm>
#include "Maths and Physics/Physics.h"
#include "Maths and Physics/vec2f.h"
#include <cmath>
#include <iostream>

ObjectHandler::ObjectHandler()
{
	
}

void ObjectHandler::renderObjects(const Shader* shader) const
{
	shader->use();
	for (Object* obj : objects)
	{
		//Shader Uniforms.
		shader->setFloat("radius", obj->getScale());
		shader->setVec2f("centrePos", obj->pos);
		shader->setVec2f("vel", vec2f(0,0));
		if(obj->phys)
			shader->setVec2f("vel", obj->getPhys()->getVelocity());

		//Store meshes and batch.
		glBindVertexArray(obj->getMesh()->getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
	}
	
}

//void renderObjectsMeshMap()
//{
//
//	for (std::pair<Mesh*, std::vector<Object*>> meshObjListPair : meshObjectMap)
//	{
//		Mesh* mesh = meshObjListPair.first;
//		glBindVertexArray(mesh->getVAO());
//		std::vector<Object*> objs = meshObjListPair.second;
//
//		for (Object* obj : objs) {
//			//uniforms for obj
//			glDrawArrays(GL_TRIANGLES, 0, 3);
//		}
//
//		glBindVertexArray(0);
//	}
//}

void ObjectHandler::collideObjects()
{
	for (int i = 0; i < objects.size() - 1; i++)
	{
		for (int j = i + 1; j < objects.size(); j++) {

			Object* A = objects.at(i);
			Object* B = objects.at(j);
			
			if (A->getName() == std::string("Ball") && B->getName() == std::string("Ball"))
			{
				Ball* ballA = dynamic_cast<Ball*>(A);
				Ball* ballB = dynamic_cast<Ball*>(B);

				vec2f disp = ballA->pos - ballB->pos;
				if (disp.lengthSq() < (ballA->getRad() + ballB->getRad()) * (ballA->getRad() + ballB->getRad()) && ballA->phys != nullptr && ballB->phys != nullptr)
				{
					float dist = std::sqrt(disp.lengthSq());
					float truDis = (ballA->getRad() + ballB->getRad());
					//float overlap = ballA->getRad() + ballB->getRad() - dist;
					vec2f D = disp;
					vec2f relVel = ballA->phys->getVelocity() - ballB->phys->getVelocity();
					if (relVel.lengthSq() == 0) continue; //Use regular collision resolution.
					
					float dotProd = dot(D, relVel);
					float sqrt = std::sqrt(dotProd*dotProd - D.lengthSq()*relVel.lengthSq() + truDis*truDis*relVel.lengthSq());
					float tCol = std::max(dotProd / relVel.lengthSq() + sqrt / relVel.lengthSq(), dotProd / relVel.lengthSq() - sqrt / relVel.lengthSq());

					ballA->pos = ballA->pos - (ballA->phys->getVelocity())*tCol;
					ballB->pos = ballB->pos - (ballB->phys->getVelocity())*tCol;

					disp = ballA->pos - ballB->pos;
					vec2f dir = disp / truDis;


					// (e + 1) / (1 + k) * (v2-v1)
					
					float relVelDotDir = dot(dir, relVel);

					float e = 0.99; float k = ballA->phys->m / ballB->phys->m;

					ballA->phys->p += - ballA->phys->m * (1 + e) / (1 + k) * relVelDotDir * dir;
					ballB->phys->p +=  ballB->phys->m * k * (1 + e) / (1 + k) * relVelDotDir * dir;
					
					ballA->pos = ballA->pos + (ballA->phys->getVelocity())*tCol;
					ballB->pos = ballB->pos + (ballB->phys->getVelocity())*tCol;

					
					
				}

			}

			/* TODO: Use map, or lambdas to use correct function for each type of object.

			void(*colFunc)(Object*, Object*);	//Pointer to relevant collision method.
			std::unordered_set<char*, char*> colPair = std::unordered_set<char*, char*>(A->getName(), B->getName());	//Collision pair type.
			colFunc = colFuncMap.at(colPair);	//Get collision function from pair.
			colFunc(A, B);	//Call collision function.
			*/
		}
	}
}

void ObjectHandler::updatePhysics(float dt)
{
	collideObjects();

	for (Physics** phys : physs) {
		
		if (*phys == nullptr) continue;
		
		(*phys)->computeForces();

	}
	for (Physics** phys : physs) {

		if (*phys == nullptr) continue;

		(*phys)->updateMomentum(dt / 2);
		(*phys)->updatePos(dt);
	}

	
	for (Physics** phys : physs) {

		if (*phys == nullptr) continue;

		(*phys)->computeForces();
		(*phys)->updateMomentum(dt / 2);
	}

}


void ObjectHandler::addObject(Object* obj)
{
	for(Object *object: objects) {
		if (obj == object)
			return;
	}

	objects.push_back(obj);
	physs.push_back(getPhysics(*obj));

	std::vector<Object*> objs = meshObjectMap[obj->getMesh()];

	if (std::find(objs.begin(), objs.end(), obj) == objs.end())
		//does not contain obj.
	{
		objs.push_back(obj);
	}
}

//Does not delete object, or physics object.
void ObjectHandler::removeObject(int index)
{
	Object* obj = objects[index];
	objects.erase(objects.begin() + index);

	//get rid of it's physics object
	Physics** phys = physs[index];
	physs.erase(physs.begin() + index);

	//get rid of it from hash map.
	Mesh* objMesh = obj->getMesh();
	std::vector<Object*> objs = meshObjectMap[objMesh];

	//find index in objs.
	int objIndex = 0;
	for (Object* tempObj: objs) {
		if (tempObj == obj) break;
		objIndex++;
	}

	objs.erase(objs.begin() + objIndex);
}

//Does not delete object, or physics object.
void ObjectHandler::removeObject(Object* obj)
{
	for (int i = 0; i < objects.size(); i++)
	{
		Object* current = objects[i];
		Physics** currentPhys = physs[i];

		if (current == obj) {
			objects.erase(objects.begin() + i);

			physs.erase(physs.begin() + i);
			return;
		}
	}

	//remove form hashmap.
	std:: vector<Object*> objs = meshObjectMap[obj->getMesh()];

	//find index in objs.
	int objIndex = 0;
	for (Object* tempObj : objs) {
		if (tempObj == obj) break;
		objIndex++;
	}

	objs.erase(objs.begin() + objIndex);
	
}


Physics** ObjectHandler::getPhysics(Object& obj)
{ 
	return &(obj.phys);
}

Object* ObjectHandler::getObject(int index) 
{
	return objects.at(index);
}

int ObjectHandler::size()
{ 
	return objects.size(); 
}

ObjectHandler::~ObjectHandler() {
	for (Object* object : objects) {
		delete(object);
	}

	objects.clear();
	physs.clear();
}

