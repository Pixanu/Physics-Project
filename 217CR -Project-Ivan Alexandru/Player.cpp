#include "Player.h"

void Player::Draw()
{
	glPushMatrix();
	glColor3f(1.f, 0.f, 1.0f);
	glTranslatef(position.x, position.y, position.z);
	glutSolidSphere(0.5f, 10, 10);
	glPopMatrix();


}

void Player::Update(float deltatime)
{
	CalculateForces();
	CheckForInput();

	acceleration = (totalForce / mass);
	velocity = velocity + (acceleration * deltatime);
	position += velocity * deltatime;
	velocity *= pow(0.4f, deltatime);

	
}

void Player::CalculateForces()
{
	totalForce = glm::vec3(0, 0, 0);
	
	/*Friction = (mass * (glm::vec3(9.8f, 0, 0)));
	totalForce += n * Friction;
	totalForce += glm::vec3(0, -9.8f, 0) * mass;
	Friction += glm::vec3(0, -9.8f, 0) * mass;
	*/
}

void Player::CheckForInput()
{
	if (GameObject::specialKeys[GLUT_KEY_UP])
	{
		totalForce += glm::vec3(0, 0, 5);
	}
	if (GameObject::specialKeys[GLUT_KEY_DOWN])
	{
		totalForce += glm::vec3(0, 0, -5);
	}
	if (GameObject::specialKeys[GLUT_KEY_LEFT])
	{
		totalForce += glm::vec3(5, 0, 0);
	}
	if (GameObject::specialKeys[GLUT_KEY_RIGHT])
	{
		totalForce += glm::vec3(-5, 0, 0);
	}
}

Player::Player(float m, glm::vec3 pos)
{
	mass = m;
	velocity = glm::vec3(0, 0, 0);
	acceleration = glm::vec3(0, 0, 0);
	totalForce = glm::vec3(0, 0, 0);
}

Player::~Player()
{
}
