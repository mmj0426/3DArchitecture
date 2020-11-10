#ifndef __APPLE_H__
#define __APPLE_H

#include "RenderableObject.h"
#include "IUpdater.h"

class Apple : public RenderableObject
{
public : 
	Apple();
	~Apple() {}

	virtual void Init() override;
	virtual void Render() override;
	virtual void Update()override;
	virtual void ShutDown()override;

private : 
	float currentPosZ;
	float speed;

};


#endif // !__APPLE_H__