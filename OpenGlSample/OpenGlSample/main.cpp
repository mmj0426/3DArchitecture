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
	Character* character = new Character("apple.obj","moon.dds");

	character->SetPosition(glm::vec3(2.0f, -2.0f, 0.0f));
	renderer->AddObject(character);

	//Camera
	renderer->SetViewMatrix(glm::lookAt(
		glm::vec3(-10, -10,- 15), // Camera is at (4,3,3), in World Space
		glm::vec3(10, 0, 0), // and looks at the origin
		glm::vec3(0, -1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	));

	do
	{
		/*if (glfwGetKey(renderer->GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
		{*/
			renderer->Update(character);
		//}
		renderer->draw();

	} while (glfwGetKey(renderer->GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(renderer->GetWindow()) == 0);

	glfwTerminate();

	delete ground;
	delete sphere;

	return 0;

}