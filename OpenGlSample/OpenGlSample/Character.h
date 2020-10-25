#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "RenderableObject.h"
#include "IUpdater.h"

class Character : public RenderableObject, public IUpdater
{
public : 
	Character(
		const char* objfilePath,
		const char* texturefile_path);
	~Character(){}

	virtual void ShutDown() override;
	virtual void InitData() override;

	virtual void Update() override;

	void Movement();

private : 
	float currentPosX;
	float currentPosZ;

	float speed;

};


#endif // !__CHARACTER_H__