#ifndef __APPLE_H__
#define __APPLE_H

#include "RenderableObject.h"
#include "IUpdater.h"

class Apple : public RenderableObject
{
public : 
	Apple(
		const char* objfilePath,
		const char* texturefile_path);
	~Apple() {}

	virtual void ShutDown()override;
	virtual void InitData() override;

	virtual void Update()override;

private : 
	float currentPosZ;
	float speed;

};


#endif // !__APPLE_H__