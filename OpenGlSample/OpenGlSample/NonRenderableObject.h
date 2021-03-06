#ifndef __NONRENDERABLEOBJECT_H__
#define __NONRENDERABLEOBJECT_H__

#include "CompositeObject.h"
#include "ObjectUpdater.h"

class NonRenderableObject : public CompositeObject, public IUpdater
{
public : 
	NonRenderableObject();
	~NonRenderableObject();

	virtual void Init() override;

	virtual void ShutDown() override;

	virtual void Update() override;
};

#endif // !__NONRENDERABLEOBJECT_H__
