//
//  class.BST.cpp
//  BST
//
//  Created by Vladimir Kuzmov on 7/3/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include "class.BST.h"

using namespace std;

BST::BST()
{
	this->Root = NULL;
}

void BST::DeleteTree(TreeNode *node)
{
	if(node != NULL)
	{
		this->DeleteTree(node->LeftTree);
		this->DeleteTree(node->RightTree);
		delete node;
	}
}

void BST::CopyTree(TreeNode *&node, TreeNode *source)
{
	if(source != NULL)
	{
		node = new TreeNode(source->Data);
		this->CopyTree(node->LeftTree, source->LeftTree);
		this->CopyTree(node->RightTree, source->RightTree);
	}
}

BST::~BST()
{
	this->DeleteTree(this->Root);
}

BST::BST(const BST &source)
{
	this->CopyTree(this->Root, source.Root);
}

BST & BST::operator =(const BST &source)
{
	if(this != &source)
	{
		this->DeleteTree(this->Root);
		this->CopyTree(this->Root, source.Root);
	}
	return * this;
}

TreeNode ** BST::FindNode(const int &x)
{
	TreeNode ** node = &(this->Root);
	while((*node) != NULL)
	{
		if((*node)->Data == x)
		{
			return node;
		}
		else if((*node)->Data > x)
		{
			node = &((*node)->LeftTree);
		}
		else
		{
			node = &((*node)->RightTree);
		}
	}
	return NULL;
}

void BST::Add(const int &x)
{
	TreeNode * newNode = new TreeNode(x);
	TreeNode ** current = &(this->Root);
    
	while((*current) != NULL)
	{
		if(x <= (*current)->Data)
		{
			current = &((*current)->LeftTree);
		}
		else
		{
			current = &((*current)->RightTree);
		}
	}
	(*current) = newNode;
}

void BST::Remove(const int &x)
{
	TreeNode ** node = FindNode(x);
	if(node != NULL)
	{
		if((*node)->LeftTree != NULL && (*node)->RightTree == NULL)
		{
			TreeNode * temp = (*node);
			(*node) = (*node)->LeftTree;
			delete temp;
		}
		else if((*node)->LeftTree == NULL && (*node)->RightTree != NULL)
		{
			TreeNode * temp = (*node);
			(*node) = (*node)->RightTree;
			delete temp;
		}
		else
		{
			(*node)->Data =	this->GetMaxElement(&(*node)->LeftTree);
		}
	}
}

int BST::GetMaxElement(TreeNode **node)
{
	while((*node)->RightTree != NULL)
	{
		node = &((*node)->RightTree);
	}
	TreeNode * temp = (*node);
	int result = (*node)->Data;
	(*node) = (*node)->LeftTree;
	delete temp;
	return result;
}

void BST::PrintTree(TreeNode *node) const
{
	if(node != NULL)
	{
		PrintTree(node->LeftTree);
		cout << node->Data << " ";
		PrintTree(node->RightTree);
	}
}

void BST::Print() const
{
	this->PrintTree(this->Root);
	cout << endl;
}