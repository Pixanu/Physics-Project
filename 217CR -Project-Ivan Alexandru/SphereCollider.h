#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include <iostream>
#include "collisondata.h"


class SphereCollider 
{
public:
	float radius;
	float distance;

	glm::vec3 position;
	bool collided;

	void Draw();
	bool CollideCheck(SphereCollider& othcol,collisonData& coldata);


	SphereCollider();
	SphereCollider(float r, glm::vec3 pos);
		~SphereCollider();
};

