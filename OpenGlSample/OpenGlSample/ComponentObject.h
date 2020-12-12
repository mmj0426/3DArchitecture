#ifndef __COMPONENTOBJECT_H__
#define __COMPONENTOBJECT_H__

#include "Object.h"

class ComponentObject : public Object
{
public : 
	virtual void Init() override {};
	virtual void ShutDown() override
	{
		Object::ShutDown();
	}

};


#endif