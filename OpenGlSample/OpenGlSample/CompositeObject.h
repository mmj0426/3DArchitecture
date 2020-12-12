#ifndef __COMPOSITEOBJECT_H__
#define __COMPOSITEOBJECT_H__

#include "ComponentObject.h"

class CompositeObject : public ComponentObject
{
public : 
	CompositeObject();
	~CompositeObject() {}

	void AddObject(ComponentObject* object);
	virtual void Init() override;
	virtual void ShutDown() override;

private : 
	std::vector<ComponentObject*>* objectTable;

};


#endif // !__COMPOSITEOBJECT_H__