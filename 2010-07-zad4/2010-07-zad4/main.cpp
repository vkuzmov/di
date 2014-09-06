//
//  main.cpp
//  2010-07-zad4
//
//  Created by Vladimir Kuzmov on 9/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <iostream>
#include "DLList.h"

node * split(DLList & l, double x)
{
    l.startForward();
    l.startBackward();
    
    while (l.forwardIter != l.backwardIter)
    {
        while (l.forwardIter->data < x)
        {
            l.nextForward();
        }
        
        while (l.backwardIter->data > x)
        {
            l.nextBackward();
        }
        
        if (l.forwardIter->data >= x && l.backwardIter->data <= x)
        {
            double temp = l.backwardIter->data;
            l.backwardIter->data = l.forwardIter->data;
            l.forwardIter->data = temp;
            
            l.Print();
            cout << endl;
        }
    }
    
    return NULL;
}

int main(int argc, const char * argv[])
{
    DLList L1;
    L1.insertAfter(L1.getEnd(), 1);
    L1.insertAfter(L1.getEnd(), 2);
    L1.insertAfter(L1.getEnd(), 3);
    L1.insertAfter(L1.getEnd(), 4);
    L1.insertAfter(L1.getEnd(), 5);
    
    cout << "L1:" << endl;
    L1.Print();
    cout << endl;
    
    DLList L2;
    L2.insertBefore(L2.getStart(), 1);
    L2.insertBefore(L2.getStart(), 2);
    L2.insertBefore(L2.getStart(), 3);
    L2.insertBefore(L2.getStart(), 4);
    L2.insertBefore(L2.getStart(), 5);
    
    cout << "L2:" << endl;
    L2.Print();
    cout << endl;
    
    cout << "Mirror: ";
    
    if (L1.mirror(L1, L2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    cout << endl;
    
    DLList L3;
    L3.insertAfter(L3.getEnd(), 8);
    L3.insertAfter(L3.getEnd(), 7);
    L3.insertAfter(L3.getEnd(), 3);
    L3.insertAfter(L3.getEnd(), 9);
    L3.insertAfter(L3.getEnd(), 5);
    L3.insertAfter(L3.getEnd(), 4);
    L3.insertAfter(L3.getEnd(), 1);
    L3.insertAfter(L3.getEnd(), 2);
    L3.insertAfter(L3.getEnd(), 6);
    
    cout << "L3:" << endl;
    L3.Print();
    cout << endl;
    
    split(L3, 5);
    
    cout << endl;
    cout << "L3:" << endl;
    L3.Print();
    cout << endl;
    
    return 0;
}

