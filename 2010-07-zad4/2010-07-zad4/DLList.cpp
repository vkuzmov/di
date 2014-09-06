//
//  DLList.cpp
//  2010-07-zad4
//
//  Created by Vladimir Kuzmov on 9/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include "DLList.h"

DLList::DLList()
{
    start = end = forwardIter = backwardIter = NULL;
}

DLList::DLList(const DLList & source)
{
    this->Copy(source);
}

DLList & DLList::operator=(const DLList & right)
{
    if (this != &right)
    {
        this->Delete();
        this->Copy(right);
    }

    return * this;
}

DLList::~DLList()
{
    this->Delete();
}

void DLList::Delete()
{
    node * temp;
    while (start)
    {
        temp = start;
        start = start->next;
        delete temp;
    }
}

void DLList::Copy(const DLList & source)
{
    start = end = forwardIter = backwardIter = NULL;
    
    node * temp = source.start;
    while (temp)
    {
        insertAfter(end, temp->data);
        temp = temp->next;
    }
}

void DLList::Print() const
{
    node * temp = start;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node * DLList::getStart()
{
    return start;
}

node * DLList::getEnd()
{
    return end;
}

void DLList::insertBefore(node * n, double x)
{
    node * newElement = new node();
    newElement->data = x;
    
    if (n == NULL)
    {
        start = end = newElement;
    }
    else
    {
        newElement->next = n;
        newElement->prev = n->prev;
        n->prev = newElement;
        
        if (n == start)
        {
            start = newElement;
        }
    }
}

void DLList::insertAfter(node * n, double x)
{
    node * newElement = new node();
    newElement->data = x;
    
    if (n == NULL)
    {
        start = end = newElement;
    }
    else
    {
        newElement->next = n->next;
        newElement->prev = n;
        n->next = newElement;
        
        if (n == end)
        {
            end = newElement;
        }
    }
}

void DLList::deleteElem(node * p, double & x)
{
    x = p->data;
    
    if (p == start)
    {
        start = start->next;
        start->prev = NULL;
    }
    else if (p == end)
    {
        end = end->prev;
        end->next = NULL;
    }
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    
    delete p;
}

void DLList::startForward(node * p)
{
    if (p != NULL)
    {
        forwardIter = p;
    }
    else
    {
        forwardIter = start;
    }
}

void DLList::startBackward(node * p)
{
    if (p != NULL)
    {
        backwardIter = p;
    }
    else
    {
        backwardIter = end;
    }
}

node * DLList::nextForward()
{
    forwardIter = forwardIter->next;
    return forwardIter;
}

node * DLList::nextBackward()
{
    backwardIter = backwardIter->prev;
    return backwardIter;
}

bool DLList::mirror(DLList & l1, DLList & l2)
{
    if (l1.start == NULL && l2.start == NULL)
    {
        return true;
    }
    
    else if (l1.start == l1.end
        && l2.start == l2.end
        && l1.start->data == l2.start->data)
    {
        return true;
    }
    else
    {
        l1.startForward();
        l2.startBackward();
        
        bool result = true;
        
        while (l1.forwardIter != NULL && l2.backwardIter != NULL)
        {
            if ((l1.forwardIter != NULL && l2.backwardIter == NULL)
                || (l1.forwardIter == NULL && l2.backwardIter != NULL))
            {
                return false;
            }
            else
            {
                result = result && (l1.forwardIter->data == l2.backwardIter->data);
            }
            
            if ( ! result) return false;
            
            l1.forwardIter = l1.nextForward();
            l2.backwardIter = l2.nextBackward();
        }

        return result;
    }
}
























