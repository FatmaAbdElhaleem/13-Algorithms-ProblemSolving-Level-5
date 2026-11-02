#pragma once
#include <iostream>
#include "clsDblLinkedList.h"


template <class T> class clsMyQueue
{
protected:
	clsDblLinkedList <T> _List;
public:
	void push(T value)
	{
		_List.InsertAtEnd(value);
	}
	void Print()
	{
		_List.Print();
	}

	bool IsEmpty()
	{
		return _List.IsEmpty();
	}

	int Size()
	{
		return _List.Size();
	}

	T front()
	{
		return _List.GetItem(0);
	}

	T back()
	{
		//return _List.GetItem(_List.Size()-1);
		return _List.GetItem(Size()-1);
	}

	void pop()
	{
		_List.DeleteFristNode();
	}

	void Reverse()
	{
		_List.Reverse();
	}

	T GetItem(int index)
	{
		return _List.GetItem(index);
	}

	bool UpdateItem(int index, T value)
	{
		return _List.UpdateItem(index, value);
	}
	void InsertAfter(int index, T value)
	{
		_List.InsertAfterIndex(index, value);
	}
	void InsertAtFront(T value)
	{
		_List.InsertAtBeginnig(value);
	}
	void InsertAtBack(T value)
	{
		_List.InsertAtEnd(value);
	}
	void Clear()
	{
		_List.Clear();
	}
};