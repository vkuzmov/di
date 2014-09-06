//
//  BinTree.cpp
//  BinTree
//
//  Created by Vladimir Kuzmov on 7/7/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include "BinTree.h"

using namespace std;

BinTree::BinTree()
{
    this->root = NULL;
}

BinTree::~BinTree()
{
    this->DeleteTree(this->root);
}

BinTree::BinTree(const BinTree &source)
{
    this->CopyTree(this->root, source.root);
}

BinTree & BinTree::operator=(const BinTree &right)
{
    if (this != &right)
    {
        this->DeleteTree(this->root);
        this->CopyTree(this->root, right.root);
    }
    return * this;
}

void BinTree::CopyTree(TreeNode * &node, TreeNode * source)
{
    if (source != NULL)
    {
        node = new TreeNode(source->data);
        this->CopyTree(node->left, source->left);
        this->CopyTree(node->right, source->right);
    }
}

void BinTree::DeleteTree(TreeNode *node)
{
    while (node != NULL)
    {
        this->DeleteTree(node->left);
        this->DeleteTree(node->right);
        delete node;
    }
}

void BinTree::Add(const int &_data)
{
	TreeNode * newNode = new TreeNode(_data);
	TreeNode ** current = &(this->root);
    
	while((*current) != NULL)
	{
		if(_data <= (*current)->data)
		{
            cout << "less than" << endl;
			current = &((*current)->left);
		}
		else
		{
            cout << "greater than" << endl;
			current = &((*current)->right);
		}
	}
	(*current) = newNode;
}

void BinTree::PrintTree(TreeNode *node) const
{
	if(node != NULL)
	{
		this->PrintTree(node->left);
		cout << node->data << " ";
		this->PrintTree(node->right);
	}
}

void BinTree::Print() const
{
	this->PrintTree(this->root);
	cout << endl;
}
