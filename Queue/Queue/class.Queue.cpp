//
//  class.Queue.cpp
//  Queue
//
//  Created by Vladimir Kuzmov on 7/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include "class.Queue.h"

using std::cout;
using std::endl;

Queue::Queue()
{
    this->top = NULL;
    this->bottom = NULL;
}

Queue::~Queue()
{
    this->Delete();
}

Queue::Queue(const Queue &source)
{
    this->Copy(source);
}

Queue & Queue::operator =(const Queue &right)
{
    if (this != &right)
    {
        this->Delete();
        this->Copy(right);
    }
    return * this;
}

void Queue::Copy(const Queue &source)
{
    QueueElement * sourceElement = source.top;
    QueueElement * lastAdded = NULL;
    this->top = NULL;
    
    while (sourceElement != NULL)
    {
        QueueElement * newElement = new QueueElement(sourceElement->data);
        
        if (lastAdded != NULL)
        {
            this->bottom->next = newElement;
        }
        else
        {
            this->top = newElement;
        }

        this->bottom = newElement;
        lastAdded = newElement;
        sourceElement = sourceElement->next;
    }

    this->bottom = lastAdded;
}

void Queue::Delete()
{
    while ( ! this->isEmpty())
    {
        QueueElement * temp = this->top;
        this->top = this->top->next;
        delete temp;
    }
}

void Queue::push(char data)
{
    cout << "pushing: " << data << endl;
    QueueElement * newElement = new QueueElement(data);
    if (this->isEmpty())
    {
        this->top = newElement;
    }
    else
    {
        this->bottom->next = newElement;
    }
    this->bottom = newElement;
}

bool Queue::pop(char & result)
{
    if (this->isEmpty())
    {
        return false;
    }
    
    QueueElement * temp = this->top;
    result = temp->data;
    cout << "popping: " << result << endl;
    this->top = this->top->next;
    delete temp;
    return true;
}

bool Queue::isEmpty() const
{
    return (this->top == NULL);
}

void Queue::print() const
{
    if (this->isEmpty())
    {
        cout << "Empty" << endl;
        return;
    }
    
    QueueElement * temp = this->top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    delete temp;
}

















