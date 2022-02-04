#pragma once
#include "GameObject.h"


class Particle : public GameObject
{
private:
	float mass;
	glm::vec3 acceleration;
	glm::vec3 velocity;

	glm::vec3 totalForce;

public:
	void Draw();
	void Update(float);
	void CalculateForces();

	Particle(float m, glm::vec3 pos);
	~Particle();
	

};

