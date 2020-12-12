#include "NonRenderableObject.h"


NonRenderableObject::NonRenderableObject()
{
	ObjectUpdater::GetInstance()->AddObject(this);
}

NonRenderableObject::~NonRenderableObject()
{
	ShutDown();
}

void NonRenderableObject::Init()
{
	
}

void NonRenderableObject::ShutDown()
{
	CompositeObject::ShutDown();
}

void NonRenderableObject::Update()
{

}
