#ifndef __OBJECTUPDATER_H__
#define __OBJECTUPDATER_H__

#include <vector>
#include <Windows.h>

#include "IUpdater.h"
#include "Singleton.h"

class ObjectUpdater : public Singleton<ObjectUpdater>, IUpdater
{
public : 
	ObjectUpdater();
	~ObjectUpdater() {}

	bool isUpdateTiming();

	void AddObject(IUpdater* src_obj);
	void Update();

private : 
	std::vector<IUpdater*> updaterObjectArray;

	LARGE_INTEGER currentFrameCounter;
	LARGE_INTEGER prevFrameCounter;
	LARGE_INTEGER frameInfo;
	double targetFrame;
	double perFrame;
};


#endif // !__OBJECTUPDATER_H__