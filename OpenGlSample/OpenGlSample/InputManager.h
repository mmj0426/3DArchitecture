#ifndef __INPUTMANAGER_H__
#define __INPUTMANAGER_H__

#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 
#include "Singleton.h"

class InputManager : public Singleton<InputManager>
{
public:
	int GetKey(int key);
};

#endif // !__INPUTMANAGER_H__