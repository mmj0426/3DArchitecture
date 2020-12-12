#include "CompositeObject.h"

CompositeObject::CompositeObject()
{
	Init();
}

void CompositeObject::AddObject(ComponentObject* object)
{
	objectTable->push_back(object);
}

void CompositeObject::ShutDown()
{
	ComponentObject::ShutDown();

	for (std::vector<ComponentObject*>::const_iterator it = objectTable->begin(); it != objectTable->end(); ++it)
	{
		delete(*it);
	}

	objectTable->clear();

	delete objectTable;
}

void CompositeObject::Init()
{
	objectTable = new std::vector<ComponentObject*>();
}