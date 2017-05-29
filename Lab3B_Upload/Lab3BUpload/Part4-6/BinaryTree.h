#pragma once
#ifndef BinaryTree_h
#define BinaryTree_h
#include "TreeNode.h"

//Karl Burke

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	bool Search(char);
	void add(char);
	void Print();
private:
	TreeNode *root;
	void destroy(TreeNode*);
	void add(TreeNode*, TreeNode*);
	bool Search(char, TreeNode*);
	void Print(TreeNode*);
};

#endif // !BinaryTree_h
