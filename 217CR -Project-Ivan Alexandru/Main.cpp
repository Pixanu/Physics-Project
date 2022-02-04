#include "GameEngine.h"


//GameObject* particle = new Particle(10.0f, glm::vec3(0, 0, 0));
GameObject* rigidBody = new Rigidbody2D(1.0f, glm::vec3 (0,0,0), 1.0f, 1.0f);
GameObject* player = new Player(1.0f, glm::vec3(0, 0, 0));

GameObject* cube = new Cube(glm::vec3(4, 0, 0));
GameEngine engine;

// Main routine.
int main(int argc, char** argv)
{
	engine.InitEngine(argc, argv, "217CR -Project-Ivan Alexandru", 500, 500);

	//engine.AddGameObject(player);
	engine.AddGameObject(rigidBody);
	engine.AddGameObject(cube);
	

	engine.StartEngine();

	return 0;
}