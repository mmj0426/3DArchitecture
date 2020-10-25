#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>

#include "FileManager.h"
#include "Renderer.h"
#include "Sphere.h"
#include "UserObject.h"
#include "SampleNonRender.h"
#include "Character.h"
#include"InputManager.h"


int main()
{
	FileManager* fileManager = FileManager::GetInstance();

	Renderer* renderer = Renderer::GetInstance();
	renderer->Initialize();

	//ground
	UserObject* ground = new UserObject("ground.obj", "container.dds");

	ground->SetPosition(glm::vec3(5.0f, -2.0f, 0.0f));
	renderer->AddObject(ground);
	
	//Sphere
	Sphere* sphere = new  Sphere();

	sphere->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	renderer->AddObject(sphere);

	//NonRenderableObject
	SampleNonRender* non_render_obj = new SampleNonRender();

	//Character
	Character* character = new Character("Hamm.obj","Hamm.dds");

	character->SetPosition(glm::vec3(5.0f, 0.0f, 0.0f));
	character->SetRotation(180.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	character->SetScale(glm::vec3(0.01f, 0.01f, 0.01f));
	renderer->AddObject(character);

	//Camera
	renderer->SetViewMatrix(glm::lookAt(
		glm::vec3(10, 10,15), // Camera is at (4,3,3), in World Space
		glm::vec3(10, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	));

	do
	{
		renderer->Update(character);
		renderer->draw();

	} while (InputManager::GetInstance()->GetKey(GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(renderer->GetWindow()) == 0);

	glfwTerminate();

	//delete ground;
	//delete sphere;

	return 0;

}