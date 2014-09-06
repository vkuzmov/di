//
//  main.cpp
//  Queue
//
//  Created by Vladimir Kuzmov on 7/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <iostream>
#include "class.Queue.h"

using namespace std;

int main(int argc, const char * argv[])
{
    Queue q;
	char result;
    
	q.push('a');
	q.push('b');
	q.push('c');
	cout << "\nq: ";
	q.print();
    
	cout << endl;
    
	Queue q1 = q;
    
	q.pop(result);
	q.pop(result);
	q.pop(result);
	cout << "\nq: ";
	q.print();
    
	cout << "\nq1: ";
	q1.print();
    
	return 0;
}

