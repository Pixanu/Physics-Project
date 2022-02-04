#include "Particle.h"

void Particle::Draw()
{
	glPushMatrix();
	glColor3f(0.f, 1.f, 0.f);

	//debug direction
	/*glBegin(GL_LINES); glVertex3f(position.x, position.y, position.z);
	glVertex3f(position.x + velocity.x, position.y + velocity.y, position.z + velocity.z);
	glEnd();*/

	glTranslatef(position.x, position.y, position.z);
	glutSolidSphere(0.5f, 10, 10);
	glPopMatrix();
}

void Particle::Update(float deltaTime)
{
	CalculateForces();

	acceleration=(totalForce/mass);
	velocity = velocity + (acceleration * deltaTime);
	velocity *= pow(0.5f, deltaTime);
	position += velocity * deltaTime;
	

}

void Particle::CalculateForces()
{
	totalForce = glm::vec3(0, 0, 0);
	totalForce += glm::vec3(0, -9.8f, 0) * mass;// add gravity later
}
Particle::Particle(float m, glm::vec3 pos)
{
	
	
		mass = m;
		velocity = glm::vec3(0, 0, 0);
		acceleration = glm::vec3(0, 0, 0);
		totalForce = glm::vec3(0, 0, 0);
}


Particle::~Particle()
{
}
