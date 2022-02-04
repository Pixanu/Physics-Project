
#include "Sphere.h"

Sphere::Sphere()
{
}


Sphere::Sphere(glm::vec3 pos, glm::float32 r): GameObject(pos)
{
	radius = r;
}

Sphere::~Sphere()
{
}

void Sphere::Draw()
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(radius, 10, 10);
	glPopMatrix();

}
