//
//  main.cpp
//  BST
//
//  Created by Vladimir Kuzmov on 7/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include "class.BST.h"

int main(int argc, const char * argv[])
{

    BST tree;
	tree.Add(6);
	tree.Add(7);
	tree.Add(3);
	tree.Add(15);
	tree.Add(18);
	tree.Add(7);
	tree.Add(2);
	tree.Add(9);
	tree.Print();
    
	BST copy;
	copy = tree;
    
	tree.Remove(7);
	tree.Remove(6);
	tree.Print();
    
	copy.Print();
    return 0;
}

