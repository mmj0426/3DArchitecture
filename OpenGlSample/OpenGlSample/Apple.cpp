#include "Apple.h"
#include "FileManager.h"

#include <iostream>
#include <random>

Apple::Apple(
	const char* objfilePath,
	const char* texturefile_path)
{
	this->objfilePath = objfilePath;
	this->texturefile_path = texturefile_path;

	InitData();
	
	std::random_device rng;

	std::uniform_int_distribution<int> dist(3, 10);

	speed = dist(rng);

	speed = speed / 100;

	std::cout << speed << std::endl;

	std::uniform_int_distribution<int> dist_x(0, 60);

	currentTranslate.x = dist_x(rng);
	currentTranslate.x = currentTranslate.x / 10;
	SetPosition(glm::vec3(currentTranslate.x, currentTranslate.y, currentTranslate.z));

	//speed = 0.1f;
}

void Apple::InitData()
{
	RenderableObject::InitData();

	FileManager::GetInstance()->LoadOBJ(objfilePath, vertices, uvs, normals);

	texture = FileManager::GetInstance()->LoadDDS(texturefile_path);

	SetBuffer();

}

void Apple::ShutDown()
{
	RenderableObject::ShutDown();
}

void Apple::Update()
{
	currentPosZ = currentTranslate.z;

	currentPosZ += speed;

	SetPosition(glm::vec3(currentTranslate.x, currentTranslate.y, currentPosZ));

	if (currentTranslate.z >= 5.0f)
	{
		//∞¥√º ªË¡¶
	}
}