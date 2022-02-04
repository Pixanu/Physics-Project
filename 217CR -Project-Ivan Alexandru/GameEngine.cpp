#include "GameEngine.h"

std::vector<GameObject*> GameEngine::objects;
int GameEngine::oldTimeSinceStart;
int GameEngine::newTimeSinceStart;
std::vector <collisonData*> GameEngine::c_data;

void GameEngine::InitEngine(int argc, char** argv, const char* windowTitle, int width, int height)
{
	glutInit(&argc, argv); //this is why we need to use argc and argv

	glutInitContextVersion(2, 0);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, height); //changed to include the parameters
	glutInitWindowPosition(100, 100);
	glutCreateWindow(windowTitle); //changed to include the parameters

	glewExperimental = GL_TRUE;
	glewInit();

	glutDisplayFunc(DrawGame); //changed to include the GameEngine function
	glutReshapeFunc(ResizeWindow); //changed to include the GameEngine function
	glutIdleFunc(UpdateGame); //changed to include the GameEngine function

	glutKeyboardFunc(keyInput);
	glutKeyboardUpFunc(keyInputUp);

	glutSpecialFunc(keySpecialInput);
	glutSpecialUpFunc(keySpecialInputUp);
}

void GameEngine::keyInput(unsigned char key, int x, int y)
{
	GameObject::keys[key] = true;
	std::cout << "Key pressed: " << key << " : " << GameObject::keys[key] << std::endl;
	//If we press escape, quit
	if (key == 27)
		exit(0);
}

void GameEngine::keyInputUp(unsigned char key, int x, int y)
{
	GameObject::keys[key] = false;
	std::cout << "Key pressed: " << key << " : " << GameObject::keys[key] << std::endl;
}

void GameEngine::keySpecialInput(int key, int x, int y)
{
	GameObject::specialKeys[key] = true;
	std::cout << "Key pressed: " << key << " : " << GameObject::specialKeys[key] << std::endl;
	//If we press escape, quit
	if (key == 27)
		exit(0);
}

void GameEngine::keySpecialInputUp(int key, int x, int y)
{
	GameObject::specialKeys[key] = false;
	std::cout << "Key pressed: " << key << " : " << GameObject::specialKeys[key] << std::endl;
}

void GameEngine::DrawGame(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	// Position the objects for viewing.
	gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->Draw();
	}

	glutSwapBuffers();
}

void GameEngine::ResizeWindow(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (float)w / (float)h, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void GameEngine::UpdateGame(void)
{
	oldTimeSinceStart = newTimeSinceStart;
	newTimeSinceStart = glutGet(GLUT_ELAPSED_TIME);

	float deltaTime = (newTimeSinceStart - oldTimeSinceStart);
	deltaTime /= 1000.f;



	for (int i = 0; i < objects.size(); ++i)
	{
		for (int j = 0; j < objects.size(); j++)
		{
			if (i == j)
			{
				continue;
			}
			else
			{
				collisonData* colldata = nullptr;
				colldata = new collisonData;
				if (objects[i]->sphereCol.CollideCheck(objects[j]->sphereCol, *colldata))
				{
					std::cout << "collided" << "\n";
					colldata->obj1 = objects[i];
					colldata->obj2 = objects[j];
					c_data.push_back(colldata);
					objects[i]->sphereCol.collided = true;
					objects[j]->sphereCol.collided = true;
					
				}
				else
				{
					objects[i]->sphereCol.collided = false;
					objects[j]->sphereCol.collided = false;
				}	
			}		
		}
	}



	for (int i = 0; i < objects.size(); ++i)
	{

		objects[i]->Update(deltaTime);
	}

	for (int i = c_data.size() - 1; i >= 0; i--)
	{
		delete c_data[i];
	}

	c_data.clear();
	glutPostRedisplay();
}

/*void CalculateImpulse();
{
	float numbr = glm::dot(-obj1)->velocity - obj2->velocity), normal);
	numbr* = (1 + obj1->ResCoef);

	float denumbr = glm::dot(normal, normal);
	denumbr *= (1 / obj1)->mass + 1 / obj2->mass);

	Impulse = numbr / denumbr;
}

void ImpulseAdd()
{
	obj1->velocity += (Impulse / obj1->mass) * normal;
	obj1->velocity -= (Impulse / obj1->mass) * normal;
}


void PenetartionFix()
{
	obj1->position += depthPen * normal;
	obj2->position -= depthPen * normal;

}*/


void GameEngine::StartEngine(void)
{
	std::cout << "Press escape to exit the game." << std::endl;
	glutMainLoop();
}

void GameEngine::CleanupEngine(void)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		delete objects[i];
	}
}

void GameEngine::AddGameObject(GameObject* object)
{
	objects.push_back(object);
}

