#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>

#include "FileManager.h"
#include "Renderer.h"
#include "Sphere.h"
#include "Ground.h"
#include "SampleNonRender.h"
#include "Character.h"
#include"InputManager.h"
#include "Apple.h"
#include "ObjectUpdater.h"


int main()
{
	FileManager* fileManager = FileManager::GetInstance();

	Renderer* renderer = Renderer::GetInstance();
	renderer->Initialize();

	ObjectUpdater* updater = ObjectUpdater::GetInstance();

	//ground
	Ground* ground = new Ground();

	//Apple
	Apple* apple_1 = new Apple();

	//NonRenderableObject
	SampleNonRender* non_render_obj = new SampleNonRender();

	//Character
	Character* hamm = new Character();


	//Camera
	renderer->SetViewMatrix(glm::lookAt(
		glm::vec3(10, 10,15), // Camera is at (4,3,3), in World Space
		glm::vec3(10, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	));


	do
	{
		//가변 프레임
		if (renderer->isRenderTiming())
		{
			renderer->Draw();
		}

		//고정 프레임
		if (updater->isUpdateTiming())
		{
			updater->Update();
		}

	} while (InputManager::GetInstance()->GetKey(GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(renderer->GetWindow()) == 0);

	ground->ShutDown();
	hamm->ShutDown();
	apple_1->ShutDown();
	non_render_obj->ShutDown();

	glfwTerminate();

	return 0;

}