//
//  class.Stack.h
//  Stack
//
//  Created by Vladimir Kuzmov on 7/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#ifndef STACK_H
#define STACK_H

struct StackElement {
    int data;
    StackElement * next;
    StackElement(int newData)
    {
        this->data = newData;
        this->next = NULL;
    }
};

class Stack {
public:
    Stack();
    ~Stack();
    Stack(const Stack &right);
    Stack & operator= (const Stack &source);
    
private:
    StackElement * top;
    
public:
    void push(int);
    bool pop(int &);
    bool isEmpty() const;
    void print() const;
    
private:
    void Copy(const Stack &);
    void Delete();
};

#endif