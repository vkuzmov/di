//
//  BinTree.h
//  BinTree
//
//  Created by Vladimir Kuzmov on 7/7/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#ifndef __BinTree__BinTree__
#define __BinTree__BinTree__

#include <iostream>

struct TreeNode {
    TreeNode * left;
    TreeNode * right;
    int data;
    
    TreeNode(const int &_data, TreeNode * _left = NULL, TreeNode * _right = NULL)
	{
		this->data = _data;
		this->left = _left;
		this->right = _right;
	}
};

class BinTree {
public:
    BinTree();
    ~BinTree();
    BinTree(const BinTree &);
    BinTree & operator= (const BinTree &);
private:
    TreeNode * root;
    void CopyTree(TreeNode * &node, TreeNode * source);
    void DeleteTree(TreeNode * node);
    void PrintTree(TreeNode * node) const;

public:
    void Add(const int &);
    void Remove(const int &);
    void Print() const;
};

#endif /* defined(__BinTree__BinTree__) */
