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

	//Sphere ������ ������ �Ҹ�ó��
	//Ư���� �Ҹ�ó�� �� ���� ���ٰ� �ص� ������
}