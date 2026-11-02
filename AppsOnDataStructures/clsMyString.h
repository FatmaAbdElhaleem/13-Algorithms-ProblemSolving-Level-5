#pragma once
#include<iostream>
#include <stack>

class clsMyString 
{
protected:
	stack<string> _Undo;
	stack<string> _Redo;
	string _value = "";
public:
	void setValue(string value)
	{
		_value = value;
		_Undo.push(_value);
		_value = _Undo.top();
	}
	string Value()
	{
		if (_Undo.empty())
			return "";
		return _Undo.top();
	}

	void Undo()
	{
		
		_Redo.push(_Undo.top());
		_Undo.pop();
	}

	void Redo()
	{
		_Undo.push(_Redo.top());
		_Redo.pop();
	}
};