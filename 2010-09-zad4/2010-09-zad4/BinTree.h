//
//  BinTree.h
//  2010-09-zad4
//
//  Created by Vladimir Kuzmov on 9/4/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#ifndef ___010_09_zad4__BinTree__
#define ___010_09_zad4__BinTree__

#include <iostream>

using namespace std;

struct TreeNode {
    char data;
    TreeNode * left;
    TreeNode * right;
    
    TreeNode(const char &x)
    {
        this->data = x;
        this->left = this->right = NULL;
    }
};

class BinTree {
public:
    TreeNode * root;
    
public:
    BinTree();
    ~BinTree();
    BinTree(const BinTree &);
    BinTree & operator= (const BinTree &);

private:
    void DeleteTree(TreeNode *);
    void CopyTree(TreeNode * &, TreeNode *);
    void PrintTree(TreeNode *) const;
    
    bool mirrorEquals(TreeNode *, TreeNode *) const;

public:
    void Add(const char &);
    void Insert(TreeNode * &, const char &);
    void Print() const;
    
    bool isSymmetric() const;
    
    TreeNode ** findLeaf(const char &);
    void appendTree(BinTree);
    
    bool contains(const char *) const;
};

#endif /* defined(___010_09_zad4__BinTree__) */
