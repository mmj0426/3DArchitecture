#include "Apple.h"
#include "FileManager.h"

#include <iostream>
#include <random>

Apple::Apple()
{
	Init();
}

void Apple::Init()
{
	std::cout << "Init" << std::endl;

	SetPosition(glm::vec3(1.5f, -2.0f, -20.0f));

	RenderableObject::Init();

	std::random_device rng;

	std::uniform_int_distribution<int> dist(3, 10);

	speed = dist(rng);

	speed = speed / 50;

	std::cout << speed << std::endl;

	std::uniform_int_distribution<int> dist_x(0, 60);

	currentTranslate.x = dist_x(rng);
	currentTranslate.x = currentTranslate.x / 10;
	SetPosition(glm::vec3(currentTranslate.x, currentTranslate.y, currentTranslate.z));
}

void Apple::Update()
{
	currentPosZ = currentTranslate.z;

	currentPosZ += speed;

	SetPosition(glm::vec3(currentTranslate.x, currentTranslate.y, currentPosZ));

	if (currentTranslate.z >= 5.0f)
	{
		//delete this;
	}
}

void Apple::Render()
{
	std::cout << "Render" << std::endl;

	objfilePath = "apple.obj";
	texturefile_path = "apple.dds";

	FileManager::GetInstance()->LoadOBJ(objfilePath, vertices, uvs, normals);

	texture = FileManager::GetInstance()->LoadDDS(texturefile_path);

	SetBuffer();
}

void Apple::ShutDown()
{
	RenderableObject::ShutDown();
}