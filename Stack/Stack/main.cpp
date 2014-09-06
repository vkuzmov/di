//
//  main.cpp
//  Stack
//
//  Created by Vladimir Kuzmov on 7/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <iostream>
#include "class.Stack.h"

using std::cout;
using std::endl;

int main(int argc, const char * argv[])
{
    Stack s;
	int i, result;
    
	for(i=1; i<4; i++)
		s.push(i);
	cout << "s: ";
	s.print();
    
	Stack s1 = s;
    
	while(!s.isEmpty())
		s.pop(result);
	cout << "s: ";
	s.print();
    
	cout << "\ns1: ";
	s1.print();
    
	return 0;
}

