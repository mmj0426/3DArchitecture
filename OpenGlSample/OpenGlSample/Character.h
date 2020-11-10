#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "RenderableObject.h"
#include "IUpdater.h"

class Character : public RenderableObject
{
public : 
	Character();
	~Character(){}

	virtual void Init() override;
	virtual void Render() override;
	virtual void Update() override;
	virtual void ShutDown() override;

private : 
	float currentPosX;
	float currentPosZ;

	float speed;

};


#endif // !__CHARACTER_H__