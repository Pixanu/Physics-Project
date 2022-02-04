#pragma once
#include "GameObject.h"
#include "SphereCollider.h"

class Rigidbody2D : public GameObject
{
private:
	float inertia;
	float orientation;

	glm::vec3 angularAcceleration;
	glm::vec3 angularVelocity;
	glm::vec3 rotationalForce; //torque
	float length;
	float width;
	float mass;
	//SphereCollider sp;

	//sphere collide



	glm::vec3 acceleration;
	glm::vec3 velocity;
	glm::vec3 totalForce;
	glm::vec3 force1;
	//glm::vec3 force2;

	
public:
	void Draw();
	void Update(float);
	void CalculateForces();
	void CheckForInput();

	Rigidbody2D(float m, glm::vec3 pos, float length, float width);
	~Rigidbody2D();

};

