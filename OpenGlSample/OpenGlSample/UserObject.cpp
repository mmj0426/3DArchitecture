#include "UserObject.h"
#include "FileManager.h"

UserObject::UserObject(
	const char* objfilePath,
	const char* texturefile_path)
{
	this->objfilePath = objfilePath;
	this->texturefile_path = texturefile_path;	

	InitData();
}

void UserObject::InitData()
{
	RenderableObject::InitData();

	FileManager::GetInstance()->LoadOBJ(objfilePath, vertices, uvs, normals);

	texture = FileManager::GetInstance()->LoadDDS(texturefile_path);

	SetBuffer();

}

void UserObject::ShutDown()
{
	RenderableObject::ShutDown();

}

void UserObject::Update()
{

}