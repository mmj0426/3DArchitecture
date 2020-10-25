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

	speed = currentTranslate.x;
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
	if (InputManager::GetInstance()->GetKey(GLFW_KEY_A) == GLFW_PRESS)
	{
		speed -= 0.01;
	}
	if (InputManager::GetInstance()->GetKey(GLFW_KEY_D) == GLFW_PRESS)
	{
		speed += 0.01;
	}

	SetPosition(glm::vec3(speed, 0.0f, 0.0f));
}

void Character::Movement()
{
	
}

//InputManager는 window 가지고있어
//Input(GLFW KEY) 함수를 가지고있어