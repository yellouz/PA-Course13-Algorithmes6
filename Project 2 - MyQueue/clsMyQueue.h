#pragma once

#include <iostream>
#include "clsDblLinkedList.h"


using namespace std;
template <class T>

class clsMyQueue
{

protected:
	clsDblLinkedList <T> _MyList;

public:

	void push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
	}

    void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	T GetItem(int Position)
	{
		return _MyList.GetItem(Position);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int Position, T NewValue)
	{
		_MyList.UpdateItem(Position, NewValue);
	}

	void InsertAfter(int Position, T Value)
	{
		_MyList.InsertAfter(Position, Value);
	}

	void InsertAtFront(T value)
	{
		_MyList.InsertAtBeginning(value);
	}

	void InsertAtBack(T value)
	{
		_MyList.InsertAtEnd(value);
	}

	void Clear()
	{
		_MyList.Clear();
	}

	

};


