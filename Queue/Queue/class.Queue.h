//
//  class.Queue.h
//  Queue
//
//  Created by Vladimir Kuzmov on 7/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#ifndef __Queue__class_Queue__
#define __Queue__class_Queue__

#include <iostream>

struct QueueElement {
    char data;
    QueueElement * next;
    QueueElement(char newData)
    {
        this->data = newData;
        this->next = NULL;
    }
};

class Queue {
public:
    Queue();
    ~Queue();
    Queue(const Queue &);
    Queue & operator= (const Queue &);

private:
    QueueElement * top;
    QueueElement * bottom;

public:
    void push(char data);
    bool pop(char &source);
    bool isEmpty() const;
    void print() const;

private:
    void Copy(const Queue &);
    void Delete();
};

#endif