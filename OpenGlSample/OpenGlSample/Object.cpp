#include "Object.h"
#include "Renderer.h"

Object::Object()
{
	translate = glm::translate(Renderer::GetInstance()->ModelMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
	rotate = glm::rotate(Renderer::GetInstance()->ModelMatrix, glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	scale = glm::scale(Renderer::GetInstance()->ModelMatrix, glm::vec3(1.0f, 1.0f, 1.0f));
}
void Object::SetPosition(glm::vec3 src_position)
{
	translate = glm::translate(Renderer::GetInstance()->ModelMatrix, src_position);
	currentTranslate = src_position;
}

void Object::SetRotation(float rot_angle, glm::vec3 axis)
{
	rotate = glm::rotate(Renderer::GetInstance()->ModelMatrix, glm::radians(rot_angle), axis);
}

void Object::SetScale(glm::vec3 scale_range)
{
	scale = glm::scale(Renderer::GetInstance()->ModelMatrix, scale_range);
}

void Object::ShutDown()
{
	
}