//
//  List.cpp
//  List
//
//  Created by Vladimir Kuzmov on 9/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include "List.h"

List::List()
{
    this->start = this->end = NULL;
}

List::~List()
{
    this->Delete();
}

List::List(const List & source)
{
    cout << "Copy Constructor" << endl;
    this->Copy(source);
}

List & List::operator=(const List &right)
{
    if (this != &right)
    {
        this->Delete();
        this->Copy(right);
    }

    return * this;
}

void List::Delete()
{
    Node * temp;
    while (start)
    {
        temp = start;
        start = start->next;
        delete temp;
    }
}

void List::Copy(const List & source)
{
    start = end = NULL;
    
    Node * temp = source.start;
    
    while (temp)
    {
        InsertToEnd(temp->data);
        temp = temp->next;
    }
}

void List::Print() const
{
    Node * temp = start;
    
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node * List::getStart()
{
    return start;
}

Node * List::getEnd()
{
    return end;
}

void List::InsertToEnd(const int & x)
{
    Node * newElement = new Node();
    newElement->data = x;
    
    if (end == NULL)
    {
        start = end = newElement;
    }
    else
    {
        end->next = newElement;
        end = newElement;
    }
}

void List::InsertToFront(const int & x)
{
    Node * newElement = new Node();
    newElement->data = x;
    newElement->next = start;
    start = newElement;
    
    if (end == NULL)
    {
        end = newElement;
    }
}

void List::InsertAfter(Node * n, const int & x)
{
    Node * newElement = new Node();
    newElement->data = x;
    newElement->next = n->next;
    n->next = newElement;
    
    if (n == end)
    {
        end = newElement;
    }
}

void List::InsertBefore(Node * n, const int & x)
{
    Node * newElement = new Node();
    newElement->data = x;
    newElement->next = n;
    
    if (n != start)
    {
        Node * temp = start;
        
        while (temp->next != n)
        {
            temp = temp->next;
        }
        temp->next = newElement;
    }
    else
    {
        start = newElement;
    }
}

void List::DeleteAfter(Node * n, int & x)
{
    Node * temp = n->next;
    x = temp->data;
    n->next = temp->next;
    delete temp;
    
    if (temp == end)
    {
        temp = n;
    }
}

void List::DeleteBefore(Node * n, int & x)
{
    if (start->next == n)
    {
        Node * temp = start;
        x = temp->data;
        start = start->next;
        delete temp;
    }
    else if (start != n)
    {
        Node * temp = start;
        while (temp->next->next != n)
        {
            temp = temp->next;
        }
        
        Node * d = temp->next;
        x = d->data;
        temp->next = d->next;
        delete d;
    }
}

void List::reverse()
{
    List reversed = List();
    Node * temp = start;
    
    while (temp)
    {
        reversed.InsertToFront(temp->data);
        temp = temp->next;
    }
    
    (*this) = reversed;
}







