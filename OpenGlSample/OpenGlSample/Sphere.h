#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "RenderableObject.h"

class Sphere : public RenderableObject
{
public : 
	Sphere();
	~Sphere() {}
	
	virtual void Init() override;

	virtual void ShutDown() override;

};
#endif // !__SPHERE_H__