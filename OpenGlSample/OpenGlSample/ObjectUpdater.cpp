#include "ObjectUpdater.h"

#include <iostream>

ObjectUpdater::ObjectUpdater()
{
	//������ ���� ���� �¾�
	targetFrame = 60;

	QueryPerformanceFrequency(&frameInfo);
	QueryPerformanceCounter(&prevFrameCounter);

	perFrame = frameInfo.QuadPart / (double)targetFrame;
	std::cout << "Target Frame : " << targetFrame << std::endl;
}

void ObjectUpdater::AddObject(IUpdater* src_obj)
{
	updaterObjectList.push_back(src_obj);
}

void ObjectUpdater::Update()
{
	for (std::vector<IUpdater*>::iterator begin = updaterObjectList.begin(); begin != updaterObjectList.end(); begin++)
	{
		(*begin)->Update();
	}
}

bool ObjectUpdater::isUpdateTiming()
{
	QueryPerformanceCounter(&currentFrameCounter);

	double time_distance = currentFrameCounter.QuadPart - prevFrameCounter.QuadPart;

	if (time_distance > perFrame)
	{
		prevFrameCounter = currentFrameCounter;
		static int count = 0;
		if (count++ > targetFrame)
		{
			std::cout << "1 second" << std::endl;

			count = 0;
		}

		//targetFrame Ȯ��
		std::cout << "dis : " << time_distance << " Frame : " << frameInfo.QuadPart / time_distance << std::endl;
		return true;
	}
	return false;
}