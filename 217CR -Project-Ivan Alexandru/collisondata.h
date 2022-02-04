#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

class GameObject;

struct collisonData 
{
	glm::vec3 normal;
	glm::vec3 collisonPoint;

	float collisonDepth;

	GameObject* obj1;
	GameObject* obj2;

};