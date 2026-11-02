#pragma once
#include <iostream>
#include "clsDoublyNode.h"

template <class T> class clsDblLinkedList 
{

protected:
	int _size=0;
	clsDoublyNode<T>* head = NULL;

public:

	bool InsertAfterIndex(int index,T value)
	{
		clsDoublyNode<T>* Node = GetNode(index);
		if (Node != NULL)
		{
			InsertAfter(Node, value);
			return true;
		}
		return false;
	}

	bool UpdateItem(int index, T value)
	{
		clsDoublyNode<T>* Node = GetNode(index);

		if (Node != NULL)
		{
			Node->data = value;
			return true;
		}
		return false; 
	}

	T GetItem(int index)
	{
		clsDoublyNode<T>* Node = GetNode(index);

		if (Node == NULL)
			return NULL;
		else
			return Node->data;
	}

	clsDoublyNode<T>* GetNode(int index) 
	{
		if (index > _size - 1 || index < 0)
			return NULL;

		clsDoublyNode<T>* Node=head;
		for (int i = 0;i < index;i++)
		{
			Node = Node->next;
		}
		return Node;
	}

	void Reverse()
	{
		// solution 1:
		//if (head == NULL)
		//	return;
		//clsDoublyNode<T>* Current= head;
		//clsDoublyNode<T>* Temp = NULL;
		//while (Current->next!=NULL)
		//{
		//	Temp = Current->next;
		//	Current->next = Current->prev;
		//	Current->prev = Temp;
		//	Current = Current->prev;
		//}
		//
		//Temp = Current->next;
		//Current->next = Current->prev;
		//Current->prev = Temp;
		//head = Current;

		// solution 2:
		clsDoublyNode<T>* Current= head;
		clsDoublyNode<T>* Temp = NULL;
		while (Current!=NULL)
		{
			Temp = Current->prev;
			Current->prev = Current->next;
			Current->next = Temp;
			Current = Current->prev;
		}
	
		if(Temp!=NULL)
		  head = Temp->prev;
	}

	void Clear()
	{
		int length = _size;
		for (int i = 0;i < length;i++)
		{
			DeleteLastNode();
		}
	}

	bool IsEmpty()
	{
		// solution 1:
		// return(head == NULL);

		// solution 2:
		return (_size == 0);
	}

	int Size()
	{
		// solution 1:
		//if (head == NULL)
		//	return 0;

		//clsDoublyNode<T>* Current = head;
		//int size = 1;

		//while(Current->next!=NULL)
		//{ 
		//	size = size + 1;
		//	Current = Current->next;
		//}
		//return size;

		// solution 2:
		return _size;
	}

	void PrintList()
	{
		clsDoublyNode<T>* Current = head;
		if (head == NULL)
			cout << "List is empty\n";

		cout << "\nLinked List Content:\n\n";
		cout << "NULL <-> ";
		while (Current != NULL)
		{
			cout << Current->data << " <-> ";
			Current = Current->next;
		}

		cout << "NULL\n";

	}

	void Print()
	{
		clsDoublyNode<T>* Current = head;
		if (head == NULL)
			cout << "List is empty\n";

		cout << "\nLinked List Content:\n\n";
		while (Current != NULL)
		{
			cout << Current->data << " ";
			Current = Current->next;
		}
		cout << endl;
	}

	void PrintListDetails()
	{
		if (head == NULL)
			cout << "List is empty\n";

		clsDoublyNode<T>* Current = head;

		cout << "\nLinked List Content:\n\n";
		while (Current != NULL)
		{
			Current->PrintNode();
			Current = Current->next;
		}

	}

	void InsertAtBeginnig(T value)
	{
		clsDoublyNode<T>* n = new clsDoublyNode(value);
		n->next = head;


		if (head != NULL)
		{
			head->prev = n;
		}

		head = n;
		_size++;
	}

	clsDoublyNode<T>* FindNode(T value)
	{

		clsDoublyNode<T>* Current = head;

		while (Current != NULL && Current->data != value)
			Current = Current->next;

		return Current;
	}

	void InsertAfter(clsDoublyNode<T>*& Current, T val)
	{
		if (Current == NULL)
			return;

		clsDoublyNode<T>* NewNode = new clsDoublyNode(val, Current, Current->next);

		if (Current->next != NULL)
			Current->next->prev = NewNode;

		Current->next = NewNode;
		_size++;
	}

	void InsertAtEnd(T val)
	{
		clsDoublyNode<T>* Current = head;

		while (Current != NULL && Current->next != NULL)
		{
			Current = Current->next;
		}

		clsDoublyNode<T>* NewNode = new clsDoublyNode<T>(val, Current, NULL);

		if (Current == NULL)
		{
			head = NewNode;
			_size++;
			return;
		}

		Current->next = NewNode;
		_size++;
	}

	void DeleteNode(clsDoublyNode<T>*& NodeToDel)
	{
		if (head == NULL || NodeToDel == NULL)
			return;

		if (head == NodeToDel)
		{
			head = head->next;
		}

		if (NodeToDel->next != NULL)
			NodeToDel->next->prev = NodeToDel->prev;

		if (NodeToDel->prev != NULL)
			NodeToDel->prev->next = NodeToDel->next;

		delete NodeToDel;
		_size--;
	}

	void DeleteFristNode()
	{
		if (head == NULL)
			return;

		clsDoublyNode<T>* NodeToDel = head;

		if (head->next != NULL)
			head->next->prev = NULL;

		head = head->next;
		delete NodeToDel;
		_size--;
	}

	void DeleteLastNode()
	{
		if (head == NULL)
			return;

		clsDoublyNode<T>* Current = head;

		if (Current->next == NULL)
		{
			head = NULL;
			_size--;
			delete Current;
			return;
		}

		while (Current->next != NULL)
			Current = Current->next;


		Current->prev->next = NULL;
		delete Current;
		_size--;
	}
};