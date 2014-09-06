//
//  class.BST.h
//  BST
//
//  Created by Vladimir Kuzmov on 7/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#ifndef __BST__class_BST__
#define __BST__class_BST__

#include <iostream>

struct TreeNode
{
	int Data;
	TreeNode * LeftTree;
	TreeNode * RightTree;
    
	TreeNode(const int &x, TreeNode * lft = NULL, TreeNode * rgt = NULL)
	{
		this->Data = x;
		this->LeftTree = lft;
		this->RightTree = rgt;
	}
};

class BST
{
private:
	TreeNode * Root;
    
public:
	BST();
	~BST();
	BST(const BST &source);
	BST & operator=(const BST &source);
    
	void Add(const int &x);
	void Remove(const int &x);
	bool Search(const int &x) const;
    
	void Print() const;
    
private:
	void DeleteTree(TreeNode * node);
	void CopyTree(TreeNode * &node, TreeNode * source);
    
	TreeNode ** FindNode(const int & x);
	int GetMaxElement(TreeNode ** node);
    
	void PrintTree(TreeNode * node) const;
};

#endif /* defined(__BST__class_BST__) */
