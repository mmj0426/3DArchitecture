#include "Sphere.h"
#include "FileManager.h"
#include "IRenderer.h"

Sphere::Sphere()
{
	InitData();
}

void Sphere::InitData()
{
	RenderableObject::InitData();

	FileManager::GetInstance()->LoadOBJ("sphere.obj", vertices, uvs, normals);

	texture = FileManager::GetInstance()->LoadDDS("moon.dds");

	SetBuffer();
}

void Sphere::ShutDown()
{
	RenderableObject::ShutDown();

	//Sphere 렌더링 데이터 소멸처리
	//특별히 소멸처리 할 일이 없다고 해도 재정의
}