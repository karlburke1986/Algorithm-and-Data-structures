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
	BinaryTree();
	void add(int);
	void destroy(TreeNode*);
	int height();
	bool hasPathSum(TreeNode*, int);
	void printPaths(TreeNode*);
	TreeNode* getRoot();
	~BinaryTree();
private:
	int height(TreeNode*);
	void add(TreeNode*, TreeNode*);
	void printPaths(TreeNode*, int[], int);
	TreeNode *root;
};


#endif // !BinaryTree_H


