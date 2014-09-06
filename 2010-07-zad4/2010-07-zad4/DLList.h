//
//  DLList.h
//  2010-07-zad4
//
//  Created by Vladimir Kuzmov on 9/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#ifndef ___010_07_zad4__DLList__
#define ___010_07_zad4__DLList__

#include <iostream>

using namespace std;

struct node {
    double data;
    node * next;
    node * prev;
};

class DLList {
    node * start;
    node * end;
    node * forwardIter;
    node * backwardIter;
    
public:
    DLList();
    DLList(const DLList &);
    DLList & operator=(const DLList &);
    ~DLList();
    
private:
    void Copy(const DLList &);
    void Delete();
    
public:
    void Print() const;
    
    node * getStart();
    node * getEnd();
    
    void insertBefore(node *, double);
    void insertAfter(node *, double);
    
    void deleteElem(node *, double &);
    
    bool mirror(DLList &, DLList &);
    
    void startForward(node * = NULL);
    void startBackward(node * = NULL);
    
    node * nextForward();
    node * nextBackward();
    
    friend node * split(DLList &, double);
};

#endif /* defined(___010_07_zad4__DLList__) */
