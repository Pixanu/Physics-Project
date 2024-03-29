#pragma once


#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <map>
#include "SphereCollider.h"


class GameObject
{
protected:
	glm::vec3 position;

public:
	GameObject();
	GameObject(glm::vec3 pos);
	~GameObject();


	SphereCollider sphereCol;


	virtual void Draw()= 0;
	virtual void Update(float);

	static std::map<char, bool>keys;
	static std::map<int, bool>specialKeys;

};

