//
//  List.h
//  List
//
//  Created by Vladimir Kuzmov on 9/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#ifndef __List__List__
#define __List__List__

#include <iostream>

using namespace std;

struct Node {
    Node * next;
    int data;
};

class List {
    Node * start;
    Node * end;
    
public:
    List();
    ~List();
    List(const List &);
    List & operator=(const List &);

private:
    void Delete();
    void Copy(const List &);
    
public:
    void Print() const;
    
    Node * getStart();
    Node * getEnd();
    
    void InsertToEnd(const int &);
    void InsertToFront(const int &);
    
    void InsertAfter(Node *, const int &);
    void InsertBefore(Node *, const int &);
    
    void DeleteAfter(Node *, int &);
    void DeleteBefore(Node *, int &);
    
    void reverse();
};

#endif /* defined(__List__List__) */
