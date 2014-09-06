//
//  main.cpp
//  2010-09-zad4
//
//  Created by Vladimir Kuzmov on 9/4/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <iostream>
#include "BinTree.h"

int main(int argc, const char * argv[])
{
    // Basic functionality
//    BinTree t;
//    t.Add('d');
//    t.Add('b');
//    t.Add('c');
//    t.Add('a');
//    t.Add('e');
//    t.Add('g');
//    t.Add('f');
//    t.Print();

    
    // Symmetric
//    BinTree t;
//    t.Insert(t.root, 'v');
//    t.Insert(t.root->left, 'a');
//    t.Insert(t.root->right, 'a');
//    
//    t.Insert(t.root->left->left, 'b');
//    t.Insert(t.root->left->right, 'c');
//    
//    t.Insert(t.root->right->left, 'c');
//    t.Insert(t.root->right->right, 'b');
//    
//    t.Print();
//    
//    if (t.isSymmetric())
//    {
//        cout << "symmetric tree" << endl;
//    }
//    else
//    {
//        cout << "non symmetric tree" << endl;
//    }
    
    // Append tree check
//    BinTree t;
//    t.Add('2');
//    t.Add('1');
//    t.Add('3');
//    t.Print();
//    
//    BinTree t2;
//    t2.Add('3');
//    t2.Add('2');
//    t2.Add('4');
//    t2.Print();
//    
//    cout << endl;
//    t.appendTree(t2);
//    t.Print();
    
    // Contains
    BinTree t;
    t.Add('d');
    t.Add('b');
    t.Add('c');
    t.Add('a');
    t.Add('e');
    t.Add('g');
    t.Add('f');
    t.Print();
    
    cout << endl;
    
    if (t.contains("degf"))
    {
        cout << "is a path" << endl;
    }
    else
    {
        cout << "is not a path" << endl;
    }
    
    return 0;
}

