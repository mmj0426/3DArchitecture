#ifndef __GROUND_H__
#define __GROUND_H__

#include "RenderableObject.h"

class Ground : public RenderableObject
{
public : 
	Ground();

	~Ground(){}

	virtual void Init() override;
	virtual void Render() override;
	virtual void Update() override;
	virtual void ShutDown() override;

};


#endif // !__GROUND_H__