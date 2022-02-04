#include "SphereCollider.h"


void SphereCollider::Draw()
{
	
		glPushMatrix();
		glColor3f(1.f, 0.f, 1.0f); //Magenta is the best debug colour!
		glTranslatef(position.x, position.y, position.z);
		glutWireSphere(radius, 10, 10);
		glPopMatrix();
	
}



bool SphereCollider::CollideCheck(SphereCollider &othcol,collisonData& coldata)
{

	float distance = sqrt(pow(position.x - othcol.position.x, 2) + pow(position.y - othcol.position.y,2)+ pow(position.z-othcol.position.z,2));
	float totalradius = radius + othcol.radius;

	if (totalradius >= distance)
	{
		coldata.collisonDepth = totalradius - distance;
		coldata.normal = glm::normalize(position - othcol.position);
		coldata.collisonPoint = position * coldata.normal * radius;
		return true;

	}
	else
	{
		return false;
	}


}



SphereCollider::SphereCollider()
{
	radius = 1.f;
}

SphereCollider::SphereCollider(float r, glm::vec3 pos)
{
	radius = r;
	position = pos;

	
}

SphereCollider::~SphereCollider()
{
}
