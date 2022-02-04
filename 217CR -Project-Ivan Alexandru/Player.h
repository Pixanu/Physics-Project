#pragma once
#include "GameObject.h"

class Player : public GameObject

{
private:
	float mass;
	glm::vec3 acceleration;
	glm::vec3 velocity;
	glm::vec3 totalForce;


	/*test 
	glm::vec3 Friction;
	glm::vec3 N; // normal at the surface
	float n = 0.9f; //friction coef water
	float g = 9.8f; // gravitational 
	*/

public:
	void Draw();
	void Update(float);
	void CalculateForces();
	void CheckForInput();

	Player(float m, glm::vec3 pos);
	~Player();


};

