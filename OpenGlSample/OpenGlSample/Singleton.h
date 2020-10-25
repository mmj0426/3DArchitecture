#ifndef __SINGLETON_H__
#define __SINGLETON_H__

template<class T>
class Singleton
{
private:
	static T* instance;

protected : 
	Singleton() {}
	virtual ~Singleton() {}

public : 
	static T* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new T();
		}
		return instance;
	}
};

template<class T> T* Singleton<T>::instance = nullptr;

#endif // !__SINGLETON_H__
