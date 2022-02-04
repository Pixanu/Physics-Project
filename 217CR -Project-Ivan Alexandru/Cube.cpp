#include "Cube.h"




Cube::Cube(glm::vec3 pos): GameObject(pos)
{
	//sv = new SphereCollider(1.0f, glm::vec3(pos));
}

Cube::~Cube()
{
	//delete sv;
}

void Cube::Draw()
{
	sphereCol.position = position;
	sphereCol.radius = 1.0f;
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(1.0f);
	glPopMatrix();

	sphereCol.Draw();
}

void Cube::Update(float deltaTime)
{
 	/*if (GameObject::specialKeys[GLUT_KEY_UP] == true)
		position.z -= 1.f * deltaTime;
	if (GameObject::specialKeys[GLUT_KEY_DOWN] == true)
		position.z += 1.f * deltaTime;
	if (GameObject::specialKeys[GLUT_KEY_LEFT] == true)
		position.x += 1.f * deltaTime;
	if (GameObject::specialKeys[GLUT_KEY_RIGHT] == true)
		position.x -= 1.f * deltaTime;*/
}


