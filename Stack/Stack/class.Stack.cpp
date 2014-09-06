#include <iostream>
#include "class.Stack.h"

using std::cout;
using std::endl;

Stack::Stack()
{
	this->top = NULL;
}

Stack::~Stack()
{
	this->Delete();
}

Stack::Stack(const Stack &source)
{
	this->Copy(source);
}

Stack & Stack::operator= (const Stack &right)
{
	if (this != &right)
	{
		this->Delete();
		this->Copy(right);
	}
	return * this;
}

void Stack::push(int data)
{
	StackElement * newElement = new StackElement(data);
	if (this->isEmpty())
	{
		this->top = newElement;
	}
	else
	{
		newElement->next = this->top;
	}
	this->top = newElement;
}

bool Stack::pop(int &result)
{
	if (this->isEmpty())
	{
		return false;
	}
    
	StackElement * temp = this->top;
	result = temp->data;
	this->top = this->top->next;
	delete temp;
	return true;
}

bool Stack::isEmpty() const
{
	return (this->top != NULL);
}

void Stack::print() const
{
	cout << "dump stack: ";
	StackElement * temp = this->top;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	delete temp;
}

void Stack::Copy(const Stack &source)
{
	StackElement * sourceElement = source.top;
	StackElement * lastAdded = NULL;
	this->top = NULL;
    
	while (sourceElement != NULL)
	{
		StackElement * newElement = new StackElement(sourceElement->data);
        
		if (lastAdded != NULL)
		{
			lastAdded->next = newElement;
		}
		else
		{
			this->top = newElement;
		}
		lastAdded = newElement;
		sourceElement = sourceElement->next;
	}
}

void Stack::Delete()
{
	while ( ! this->isEmpty())
	{
		StackElement * temp = this->top;
		this->top = this->top->next;
		delete temp;
	}
}
