#ifndef __SAMPLENONRENDER_H__
#define __SAMPLENONRENDER_H__

#include "NonRenderableObject.h"

class SampleNonRender : public NonRenderableObject
{
public : 
	SampleNonRender();
	~SampleNonRender();

	virtual void Init() override;

	virtual void ShutDown() override;

	virtual void Update() override;
};

#endif // !__SAMPLENONRENDER_H__