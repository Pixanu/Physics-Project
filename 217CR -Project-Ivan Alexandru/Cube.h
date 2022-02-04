#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include "GameObject.h";
#include "SphereCollider.h"


class Cube : public GameObject
{
private:
	//glm::vec3 position;
public: 

	Cube(glm::vec3 pos);
	~Cube();


	virtual void Draw();
	void Update(float);
};

