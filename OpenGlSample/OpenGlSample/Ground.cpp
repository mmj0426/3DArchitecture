#include "Ground.h"
#include "FileManager.h"

Ground::Ground()
{
	Init();
}

void Ground::Init()
{
	RenderableObject::Init();

	SetPosition(glm::vec3(1.5f, -2.0f, -8.0f));
	SetScale(glm::vec3(2.0f, 2.0f, 10.0f));
}

void Ground::Render()
{
	this->objfilePath = "ground.obj";
	this->texturefile_path = "ground.dds";

	FileManager::GetInstance()->LoadOBJ(objfilePath, vertices, uvs, normals);

	texture = FileManager::GetInstance()->LoadDDS(texturefile_path);

	SetBuffer();
}

void Ground::Update()
{

}


void Ground::ShutDown()
{
	RenderableObject::ShutDown();

}