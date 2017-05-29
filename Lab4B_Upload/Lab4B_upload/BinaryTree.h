#pragma once
#ifndef BinaryTree_H
#define BinaryTree_H

//Karl Burke
class TreeNode
{
	friend class BinaryTree;
public:
	TreeNode();
	TreeNode(int);
private:	
	TreeNode *left;
	int data;
	TreeNode *right;
};

class BinaryTree
{
public:
	bool isBSTV1(TreeNode*);
	bool isBSTV2(TreeNode*);
	int minValue(TreeNode*);
	int maxValue(TreeNode*);
	TreeNode* getRoot();
	BinaryTree();
	void add(int);
	void destroy(TreeNode*);
	int height();
	~BinaryTree();
private:
	int height(TreeNode*);
	void add(TreeNode*, TreeNode*);
	bool isBSTV2(TreeNode*, int, int);
	TreeNode *root;
};


#endif // !BinaryTree_H
