#pragma once
#include <iostream>
#include "clsMyQueue.h"

template<class T> class clsMyStack:private clsMyQueue<T>
{
public:
	void push(T value)
	{
		clsMyQueue<T>::InsertAtFront(value);
	}

	T Top()
	{
		return clsMyQueue<T>::front();
	}

	T Bottom()
	{
		return clsMyQueue<T>::back();
	}
};
