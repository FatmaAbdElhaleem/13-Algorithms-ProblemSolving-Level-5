#pragma once
#include <iostream>
#include "clsMyQueueArr.h"

template<class T> class clsMyStackArr :public clsMyQueueArr<T>
{
public:
	void push(T value)
	{
		clsMyQueueArr<T>::InsertAtFront(value);
	}

	T Top()
	{
		return clsMyQueueArr<T>::front();
	}

	T Bottom()
	{
		return clsMyQueueArr<T>::back();
	}
};
