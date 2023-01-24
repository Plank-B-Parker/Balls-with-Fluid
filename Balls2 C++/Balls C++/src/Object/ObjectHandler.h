#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Physics;
class Shader;
class Object;
struct Mesh;



class ObjectHandler {

	friend Object;

private:

	std::vector<Object*> objects;
	std::vector<Physics**> physs;
	std::unordered_map<Mesh*, std::vector<Object*> > meshObjectMap;

	//std::unordered_map<std::unordered_set<char*,char*> , void (*)(Object*, Object*)> colFuncMap;

	Physics** getPhysics(Object& obj);

public:

	ObjectHandler();
	~ObjectHandler();

	void updatePhysics(float dt);
	void collideObjects();
	void renderObjects(const Shader* shader) const;
	

	int size();
	Object* getObject(int index);
	void addObject(Object* obj);

	void removeObject(Object* obj);
	void removeObject(int index);
}; 