//
//  main.cpp
//  List
//
//  Created by Vladimir Kuzmov on 9/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <iostream>
#include "List.h"

int main(int argc, const char * argv[])
{
    List L1;
    L1.InsertToEnd(1);
    L1.InsertToEnd(2);
    L1.InsertToEnd(3);
    L1.InsertToEnd(4);
    L1.InsertToEnd(5);
    L1.InsertToEnd(3);
    
    cout << "L1" << endl;
    L1.Print();
    cout << endl;
    
    cout << "L1 reversed" << endl;
    L1.reverse();
    L1.Print();
    cout << endl;
    
    return 0;
}

