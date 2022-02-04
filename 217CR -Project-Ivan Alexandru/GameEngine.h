#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

#pragma comment(lib, "glew32.lib") 

#include "Cube.h"
#include <iostream>
#include <vector>
#include "Sphere.h"
#include "Particle.h"
#include "Player.h"
#include "Rigidbody2D.h"
#include "GameObject.h"
#include "SphereCollider.h"
class GameEngine
{
public:
	void InitEngine(int argc, char** argv, const char* windowTitle, int width, int height);
	static void keyInput(unsigned char key, int x, int y);
	static void keyInputUp(unsigned char key, int x, int y);
	static void keySpecialInput(int key, int x, int y);
	static void keySpecialInputUp(int key, int x, int y);
	void StartEngine(void);
	void AddGameObject(GameObject* object);

private:


	/*int numbr;
	int denumbr;
	int Impulse;
	int depthPen;*/

	static int newTimeSinceStart;
	static int oldTimeSinceStart;
	static std::vector<GameObject*>objects;
	static std::vector<collisonData*>c_data;


	GameObject* particle = new Particle(1.0f, glm::vec3(0, 0, 0));
	GameObject* player = new Player(1.0f, glm::vec3(0, 0, 0));
	GameObject* rigidbody2D = new Rigidbody2D(1.0f, glm::vec3(0, 0, 0), 1.0f, 1.0f);
	static void DrawGame(void);
	static void ResizeWindow(int w, int h);
	static void UpdateGame(void);
	void CleanupEngine(void);
};

