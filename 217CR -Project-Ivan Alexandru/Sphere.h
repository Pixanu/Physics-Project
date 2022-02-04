#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include "GameObject.h"


class Sphere : public GameObject
{

private:
	glm::float32 radius;
public:
	Sphere();
	Sphere(glm::vec3 pos, glm::float32 r);
	~Sphere();


	virtual void Draw();
};
