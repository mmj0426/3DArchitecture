#include "SampleNonRender.h"

SampleNonRender::SampleNonRender()
{
	Init();
}

void SampleNonRender::Init()
{
	NonRenderableObject::Init();
}

void SampleNonRender::Update()
{
	NonRenderableObject::Update();
}

void SampleNonRender::ShutDown()
{
	NonRenderableObject::ShutDown();
}

SampleNonRender::~SampleNonRender()
{
	ShutDown();
}