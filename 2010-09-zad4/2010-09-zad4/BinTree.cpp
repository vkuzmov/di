//
//  BinTree.cpp
//  2010-09-zad4
//
//  Created by Vladimir Kuzmov on 9/4/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include "BinTree.h"
#include <string>

BinTree::BinTree()
{
    root = NULL;
}

BinTree::~BinTree()
{
    DeleteTree(root);
}

BinTree::BinTree(const BinTree & source)
{
    CopyTree(root, source.root);
}

BinTree & BinTree::operator=(const BinTree & right)
{
    if (this != &right)
    {
        DeleteTree(root);
        CopyTree(root, right.root);
    }
    
    return * this;
}

void BinTree::DeleteTree(TreeNode * node)
{
    if (node != NULL)
    {
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
    }
}

void BinTree::CopyTree(TreeNode * &node, TreeNode * source)
{
    if (source != NULL)
    {
        node = new TreeNode(source->data);
        CopyTree(node->left, source->left);
        CopyTree(node->right, source->right);
    }
}

void BinTree::PrintTree(TreeNode * node) const
{
    if (node != NULL)
    {
        PrintTree(node->left);
        cout << node->data << " ";
        PrintTree(node->right);
    }
}

void BinTree::Add(const char & x)
{
    TreeNode * newNode = new TreeNode(x);
    TreeNode ** current = &(root);
    
    while (*current != NULL)
    {
        if (x <= (*current)->data)
        {
            current = &((*current)->left);
        }
        else
        {
            current = &((*current)->right);
        }
    }
    
    (*current) = newNode;
}

void BinTree::Insert(TreeNode * & node, const char & x)
{
    node = new TreeNode(x);
}

void BinTree::Print() const
{
    PrintTree(root);
    cout << endl;
}

bool BinTree::mirrorEquals(TreeNode * leftTree, TreeNode * rightTree) const
{
    if (leftTree == NULL || rightTree == NULL)
    {
        return leftTree == NULL && rightTree == NULL;
    }
    
    return
        leftTree->data == rightTree->data
        && mirrorEquals(leftTree->left, rightTree->right)
        && mirrorEquals(leftTree->right, rightTree->left);
}

bool BinTree::isSymmetric() const
{
    return mirrorEquals(root->left, root->right);
}

TreeNode ** BinTree::findLeaf(const char & x)
{
    TreeNode ** node = &(root);
    
    while ((*node) != NULL)
    {
        if ((*node)->data == x && (*node)->left == NULL && (*node)->right == NULL)
        {
            return node;
        }
        else if (x <= (*node)->data)
        {
            node = &((*node)->left);
        }
        else
        {
            node = &((*node)->right);
        }
    }

    return NULL;
}

void BinTree::appendTree(BinTree t)
{
    TreeNode ** leaf = findLeaf(t.root->data);
    
    while (leaf)
    {
        CopyTree((*leaf), t.root);
        leaf = findLeaf(t.root->data);
    }
}

bool BinTree::contains(const char * path) const
{
    cout << path << " - ";
    
    TreeNode * node = root;
    size_t path_length = strlen(path);
    
    for (size_t i = 0; i < path_length; i++)
    {
        if (node->data == path[i])
        {
            if (i+1 < path_length)
            {
                if (path[i+1] <= node->data)
                {
                    node = node->left;
                }
                else
                {
                    node = node->right;
                }
            }
        }
        else
        {
            return false;
        }
    }
    
    return true;
}




























