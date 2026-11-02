#pragma once
#include<iostream>
#include "clsDynamicArray.h"

template<class T>
class  clsMyQueueArr
{
protected:
	clsDynamicArray<T> dynamicArray;
public:
	void push(T value)
	{
		dynamicArray.InsertAtEnd(value);
	}
	void Print()
	{
		dynamicArray.Print();
	}
	int Size()
	{
		return dynamicArray.Size();
	}

	T front()
	{
		return dynamicArray.GetItem(0);
	}

	T back()
	{
		return dynamicArray.GetItem(Size() - 1);
	}

	void pop()
	{
		dynamicArray.DeleteFirstItem();
	}

	T GetItem(int index)
	{
		return dynamicArray.GetItem(index);
	}

	void Reverse()
	{
		dynamicArray.Reverse();
	}

	void UpdateItem(int index, T value)
	{
		dynamicArray.SetItem(index, value);
	}

	bool IsEmpty()
	{
		return dynamicArray.IsEmpty();
	}

	void InsertAfter(int index, T value)
	{
		dynamicArray.InsertAfter(index, value);
	}
	void InsertAtFront(T value)
	{
		dynamicArray.InsertAtBeginning(value);
	}
	void InsertAtBack(T value)
	{
		dynamicArray.InsertAtEnd(value);
	}
	void Clear()
	{
		dynamicArray.Clear();
	}
};