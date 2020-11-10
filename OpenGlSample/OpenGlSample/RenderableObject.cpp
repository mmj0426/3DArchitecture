#include "RenderableObject.h"
#include "FileManager.h"
#include "ObjectUpdater.h"
#include "Renderer.h"

RenderableObject::RenderableObject()
{
	Renderer::GetInstance()->AddObject(this);
	ObjectUpdater::GetInstance()->AddObject(this);
}

void RenderableObject::Init()
{
	textureID = glGetUniformLocation(programID, "myTextureSampler");
	programID = FileManager::GetInstance()->LoadShaders("vs_w7.shader", "fs_w7.shader");
	this->Render();
}

void RenderableObject::SetBuffer()
{
	matrixID = glGetUniformLocation(programID, "MVP");
	viewMatrixID = glGetUniformLocation(programID, "V");
	modelMatrixID = glGetUniformLocation(programID, "M");

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

	glGenBuffers(1, &normalbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);
}

void RenderableObject::ShutDown()
{
	Object::ShutDown();

	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(programID);
}
