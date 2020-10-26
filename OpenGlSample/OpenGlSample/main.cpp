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
#include "Apple.h"


int main()
{
	FileManager* fileManager = FileManager::GetInstance();

	Renderer* renderer = Renderer::GetInstance();
	renderer->Initialize();

	//ground
	UserObject* ground = new UserObject("ground.obj", "road.dds");

	ground->SetPosition(glm::vec3(1.5f, -2.0f, -8.0f));
	ground->SetScale(glm::vec3(2.0f, 2.0f, 10.0f));
	renderer->AddObject(ground);

	//Apple
	Apple* apple_1 = new Apple("apple.obj", "apple.dds");
	apple_1->SetPosition(glm::vec3(1.5f, -2.0f, -20.0f));
	renderer->AddObject(apple_1);

	Apple* apple_2 = new Apple("apple.obj", "apple.dds");
	apple_2->SetPosition(glm::vec3(0.0f, -2.0f, -20.0f));
	renderer->AddObject(apple_2);

	Apple* apple_3 = new Apple("apple.obj", "apple.dds");
	apple_3->SetPosition(glm::vec3(6.0f, -2.0f, -20.0f));
	renderer->AddObject(apple_3);

	//NonRenderableObject
	SampleNonRender* non_render_obj = new SampleNonRender();

	//Character
	Character* hamm = new Character("Hamm.obj","Hamm.dds");

	hamm->SetPosition(glm::vec3(10.0f, -1.0f, 5.0f));
	hamm->SetRotation(180.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	hamm->SetScale(glm::vec3(0.01f, 0.01f, 0.01f));
	renderer->AddObject(hamm);

	//Camera
	renderer->SetViewMatrix(glm::lookAt(
		glm::vec3(10, 10,15), // Camera is at (4,3,3), in World Space
		glm::vec3(10, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	));

	do
	{
		renderer->draw();
		renderer->Update(apple_1);
		renderer->Update(apple_2);
		renderer->Update(apple_3);
		renderer->Update(hamm);

	} while (InputManager::GetInstance()->GetKey(GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(renderer->GetWindow()) == 0);

	glfwTerminate();

	delete ground;
	delete apple_1;
	delete apple_2;
	delete apple_3;
	delete hamm;

	return 0;

}