#ifndef __RENDERABLEOBJECT_H__
#define __RENDERABLEOBJECT_H__

#include "Object.h"
#include "IRenderer.h"
#include "IUpdater.h"

class RenderableObject : public Object, public IRenderer, public IUpdater
{
public:
	RenderableObject();
	~RenderableObject(){}

	void SetBuffer();

	virtual glm::mat4  GetTranslate() override { return Object::GetTranslate();  }
	virtual glm::mat4 GetRotate() override { return Object::GetRotate(); }
	virtual glm::mat4 GetScale() override { return Object::GetScale(); }

	virtual void Init() override;
	virtual void ShutDown() override;

	void SetRenderData();

	const char* objfilePath;
	const char* texturefile_path;
	
};


#endif // !__OBJECT_H__#pragma once
