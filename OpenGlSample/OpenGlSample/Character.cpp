#include <iostream>

#include "Character.h"
#include "FileManager.h"
#include"InputManager.h"

#include "include/GLFW/glfw3.h" 

Character::Character(
	const char* objfilePath,
	const char* texturefile_path)
{
	this->objfilePath = objfilePath;
	this->texturefile_path = texturefile_path;

	InitData();
	speed = 0.05f;
}

void Character::InitData()
{
	RenderableObject::InitData();

	FileManager::GetInstance()->LoadOBJ(objfilePath, vertices, uvs, normals);

	texture = FileManager::GetInstance()->LoadDDS(texturefile_path);

	SetBuffer();

}

void Character::ShutDown()
{
	RenderableObject::ShutDown();
}

void Character::Update()
{
	currentPosX = currentTranslate.x;
	currentPosZ = currentTranslate.z;

	if (InputManager::GetInstance()->GetKey(GLFW_KEY_A) == GLFW_PRESS)
	{
		currentPosX -= speed;
	}
	if (InputManager::GetInstance()->GetKey(GLFW_KEY_D) == GLFW_PRESS)
	{
		currentPosX += speed;
	}

	SetPosition(glm::vec3(currentPosX, currentTranslate.y, currentPosZ));
}
