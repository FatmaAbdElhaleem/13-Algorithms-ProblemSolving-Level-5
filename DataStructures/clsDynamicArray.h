#pragma once
#include <iostream>
using namespace std;

template<class T>
class clsDynamicArray
{
private:
	int _size;
	T* _tempArr=NULL;
public:
	T* arr = NULL;

	clsDynamicArray(int size=0)
	{
		if (size < 0)
			size = 0;

		_size = size;
		arr=new T[_size];
	}

	~ clsDynamicArray()
	{
		delete[] arr;
	}

    bool SetItem(int index, T value)
	{
		if (_size < 0 || index >= _size)
			return false;

		//*(arr + index) = value;
		arr[index] = value;
		return true;
	}

	bool IsEmpty()
	{
		return (_size == 0);
	}

	int Size()
	{
		return _size;
	}
	void Print()
	{
		
		for (int i = 0;i < _size;i++)
		{
			//cout << *(arr + i)<<" ";
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void Resize(int newSize)
	{
		if (newSize < 0)
			newSize = 0;

		 _tempArr = new T[newSize];

		if(newSize<_size)
		  _size = newSize;

		for (int i = 0;i < _size;i++)
		{
		   _tempArr[i] = arr[i];
		}
		
		_size = newSize;
		delete[] arr;
		arr = _tempArr;
	}
	T GetItem(int index)
	{ 
		return arr[index];
	}

	void Clear()
	{
		_tempArr = new T[0];
		_size = 0;
		delete[] arr;
		arr = _tempArr;
	}

	void Reverse()
	{
		// solution 1:
		//if (_size == 0)
		//	return;

		//_tempArr = new T[_size];

		//for (int i = 0;i < _size;i++)
		//{
		//	_tempArr[i] = arr[i];
		//}

		//int s = _size;
		//for (int i = 0;i < _size;i++)
		//{
		//	arr[i] = _tempArr[s - 1];
		//	s--;
		//}
		//delete[] _tempArr;

		// solution 2:
		if (_size == 0)
			return;

		_tempArr = new T[_size];

		int counter = 0;
		for (int i = _size-1;i >=0;i--)
		{
			_tempArr[counter] = arr[i];
			counter++;
		}
		delete[] arr;
		arr = _tempArr;
		_tempArr = NULL;
	}

	bool DeleteItemAt(int index)
	{
		if (index < 0 || index >= _size)
			return false;

		_tempArr = new T[_size - 1];

		//solution 1:
		//int counter = 0;
		//for (int i = 0;i < _size;i++)
		//{
		//	if (i==index) 
		//		i++;
		//
		//	_tempArr[counter] = arr[i];
		//	counter++;
		//}

		// solution 2:
		for(int i=0;i<index;i++)
			_tempArr[i] = arr[i];

		for (int i =index+1;i < _size;i++)
			_tempArr[i-1] = arr[i];
		

		_size--;
		delete[] arr;
		arr = _tempArr;
		return true;
	}

	bool DeleteFirstItem()
	{
		return DeleteItemAt(0);
	}

	bool DeleteLastItem()
	{
		return DeleteItemAt(_size-1);
	}

	int Find(T item)
	{
		for (int i = 0;i < _size;i++)
		{
			if(arr[i]==item)
			{
				return i;
			}
		}
		return -1;
	}

	bool DeleteItem(T item)
	{
		int index = Find(item);
		return DeleteItemAt(index);
	}

	bool InsertAt(int index,T value)
	{
		if (index < 0 || index > _size)
			return false ;

		// solution 1:
		//T* _TempArr = new T[_size - index];

		//for (int i = index;i < _size;i++)
		//{
		//	_TempArr[i-index] = arr[i];
		//}

		//Resize(_size + 1);
		//arr[index] = value;

		//for (int i = index+1;i < _size;i++)
		//{
		//	arr[i] = _TempArr[i-index-1];
		//}

		//delete[] _TempArr;
		// return true;

		//solution 2:

		_size++;
		_tempArr = new T[_size];

		for (int i = 0;i < index;i++)
		{
			_tempArr[i] = arr[i];
		}
		_tempArr[index] = value;

		for (int i = index;i < _size-1;i++)
		{
			_tempArr[i+1] = arr[i];
		}

		delete[] arr;
		arr = _tempArr;
		return true;
	}

	bool InsertAtBeginning(T value)
	{
		return InsertAt(0, value);
	}

	bool InsertBefore(int index, T value)
	{
		if(index<1)
			return InsertAt(0, value);

		return InsertAt(index-1, value);
	}

	bool InsertAfter(int index, T value)
	{
		if(index>=_size)
			return InsertAt(_size, value);

		return InsertAt(index +1, value);
	}

	bool InsertAtEnd(T value)
	{
		return InsertAt(_size, value);
	}
};
