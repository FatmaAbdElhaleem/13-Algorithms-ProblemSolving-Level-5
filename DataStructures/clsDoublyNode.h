#pragma once
#include <iostream>
using namespace std;

template <class T> class clsDoublyNode
{
public:

	T data;
	clsDoublyNode<T>* prev=NULL;
	clsDoublyNode<T>* next=NULL;

	clsDoublyNode(T data, clsDoublyNode* prev = NULL, clsDoublyNode* next = NULL)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}

	clsDoublyNode() {}

	void PrintNode()
	{
		if (prev == NULL)
			cout << "NULL";
		else
			cout << prev->data;

		cout << " <-> " << data << " <-> ";

		if (next == NULL)
			cout << "NULL";
		else
			cout << next->data << endl;
	}
};