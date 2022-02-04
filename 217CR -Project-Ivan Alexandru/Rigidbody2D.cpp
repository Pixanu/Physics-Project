#include "Rigidbody2D.h"
#include <iostream>
#include <glm/gtx/string_cast.hpp>





void Rigidbody2D::Draw()
{
	glPushMatrix(); //dont affect other objects, only this one so take a copy of the matrix and put it on the stack
	glTranslatef(position.x, position.y, position.z); //then this happens
	glRotatef(glm::degrees(orientation), 0, 0, 1); //this really happens first
	glColor3f(1.f, 1.f, 1.f);

	glBegin(GL_QUADS);
	glVertex3f(-length, width, 0); //top left
	glVertex3f(length, width, 0); //top right
	glVertex3f(length, -width, 0); //bottom right
	glVertex3f(-length, -width, 0); //bottom left
	glEnd();

	glPointSize(5.0f); // so we can see the point better

	glColor3f(0.f, 0.f, 0.f);
	glBegin(GL_POINTS);
	//at the middle of object
	glVertex3f(0, 0, 0);
	glEnd();
	glPopMatrix(); //forget about what we've done to this object so push off the stack - we are back to before the glPushMatrix() happened


		//sphere collider draw
	
	sphereCol.Draw();
}

void Rigidbody2D::Update(float deltatime)
{
	sphereCol.position = position;
	CalculateForces();
	CheckForInput();


	//linear
	acceleration = totalForce / mass;
	velocity = velocity + (acceleration * deltatime);
	//Dampen
	velocity *= pow(0.4f, deltatime);

	position = position+(velocity * deltatime);
	//sp->position = position;
	//Angular
	angularAcceleration = rotationalForce / inertia;
	angularVelocity = angularVelocity + angularAcceleration * deltatime;
	angularVelocity *= pow(0.4f, deltatime);

	orientation = orientation + angularVelocity.z * deltatime;

	//debub angular velocity
	//std::cout << glm::to_string(angularVelocity) << std::endl;

	

}

void Rigidbody2D::CalculateForces()
{
	totalForce = glm::vec3(0, 0, 0);
	totalForce += force1;

	rotationalForce = glm::vec3(0, 0, 0);

	//cross prod havs been moved to a key input 
	//rotationalForce += glm::cross(glm::vec3(1, 1, 0), glm::vec3(1, 0, 0));


	//debug rotation
	//std::cout << rotationalForce.x << " " << rotationalForce.y << " " << rotationalForce.z << std::endl;
}

void Rigidbody2D::CheckForInput()
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

	if(GameObject::keys['p'])
		rotationalForce += glm::cross(glm::vec3(1, 1, 0), glm::vec3(1, 0, 0));
}

Rigidbody2D::Rigidbody2D(float m, glm::vec3 pos, float length, float width) : GameObject(pos)
{

	this->length = length;
	this->width = width;
	
	force1 = glm::vec3(0, 0, 0);
	//force2 = glm::vec3(2, 0, 0);
	mass = m;

	/*
	velocity = glm::vec3(0, 0, 0);
	acceleration = glm::vec3(0, 0, 0);
	totalForce = glm::vec3(0, 0, 0);*/

	inertia = 1.0f / 6.0f;
	std::cout << "Inertia= " << inertia << std::endl;
	angularAcceleration = glm::vec3(0, 0, 0);
	angularVelocity = glm::vec3(0, 0, 0);
	orientation = 0.0f;
	


}

Rigidbody2D::~Rigidbody2D()
{
	
}
