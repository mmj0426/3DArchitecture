#include <iostream>

#include "Character.h"
#include "FileManager.h"
#include"InputManager.h"

#include "include/GLFW/glfw3.h" 

Character::Character()
{
	Init();
}

void Character::Init()
{
	RenderableObject::Init();

	SetPosition(glm::vec3(10.0f, -1.0f, 5.0f));
	SetRotation(180.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	SetScale(glm::vec3(0.01f, 0.01f, 0.01f));

	speed = 0.05f;
}

void Character::Render()
{
	this->objfilePath = "Hamm.obj";
	this->texturefile_path = "Hamm.dds";

	FileManager::GetInstance()->LoadOBJ(objfilePath, vertices, uvs, normals);

	texture = FileManager::GetInstance()->LoadDDS(texturefile_path);

	SetBuffer();
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


void Character::ShutDown()
{
	RenderableObject::ShutDown();
}