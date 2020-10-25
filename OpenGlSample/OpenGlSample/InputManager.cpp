#include "InputManager.h"
#include "Renderer.h"

int InputManager::GetKey(int key)
{
	return glfwGetKey(Renderer::GetInstance()->GetWindow(), key);
}
