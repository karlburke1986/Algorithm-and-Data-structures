#include "BinaryTree.h"
#include <stddef.h>
#include <iostream>

using namespace std;

TreeNode::TreeNode()
{
	data = NULL;
}

TreeNode::TreeNode(int num)
{
	data = num;
	left = NULL;
	right = NULL;
}

BinaryTree::BinaryTree()
{
	root = NULL;
}

/***************************************************************************************

*    Usage: Modified
*    Title: N/A
*    Author: hankaixyz
*    Date: 23/02/2017
*    Code version: N/A
*    Availability: http://stackoverflow.com/questions/8183985/recursive-insertion-of-bst
*
***************************************************************************************/

void BinaryTree::add(TreeNode *toAdd, TreeNode *addHere)
{
	if (toAdd->data < addHere->data)
	{
		if (addHere->left == NULL)
		{
			addHere->left = toAdd;
		}
		else
		{
			add(toAdd, addHere->left);
		}
	}
	else if (toAdd->data >= addHere->data)
	{
		if (addHere->right == NULL)
		{
			addHere->right = toAdd;
		}
		else
		{
			add(toAdd, addHere->right);
		}
	}
}

void BinaryTree::add(int num)
{
	TreeNode *temp = new TreeNode(num);

	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		add(temp, root);
	}
}

/***************************************************************************************

*    Usage: Modified
*    Title: N/A
*    Author: N/A
*    Date: 23/02/2017
*    Code version: N/A
*    Availability: http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
*
***************************************************************************************/

int BinaryTree::height()
{
	return height(root);
}

int BinaryTree::height(TreeNode *node)
{
	int leftHeight = 0;
	int rightHeight = 0;

	if (root == NULL)
	{
		return -1;
	}
	else
	{

		if (node->left != NULL)
		{
			leftHeight += 1 + height(node->left);
		}

		if (node->right != NULL)
		{
			rightHeight += 1 + height(node->right);
		}

		if (leftHeight > rightHeight)
		{
			return leftHeight;
		}
		else
		{
			return rightHeight;
		}
	}

}

/***************************************************************************************

*    Usage: Used
*    Title: Root to leaf path with given sum in binary tree
*    Author: Shridhar R. Kulkarni
*    Date: 26/02/2017
*    Code version: N/A
*    Availability: http://codereview.stackexchange.com/questions/143486/root-to-leaf-path-with-given-sum-in-binary-tree/143504

***************************************************************************************/

bool BinaryTree::hasPathSum(TreeNode* node, int sum)
{
	if (node == NULL)
	{
		return sum == 0;
	}

	return(hasPathSum(node->left, sum - node->data) ||
		hasPathSum(node->right, sum - node->data));
}


/***************************************************************************************

*    Usage: Modified
*    Title: Given a binary tree, print all root-to-leaf paths
*    Author: Tushar Roy
*    Date: 26/02/2017
*    Code version: N/A
*    Availability: http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
*
***************************************************************************************/

void BinaryTree::printPaths(TreeNode *node)
{
	int path[1000];
	printPaths(node, path, 0);
}

void BinaryTree::printPaths(TreeNode *node, int path[], int pathLen)
{
	if (node == NULL)
	{
		return;
	}

	path[pathLen] = node->data;

	if (node->left == NULL && node->right == NULL)
	{
		for (int i = 0; i <= pathLen; i++)
		{
			cout << path[i] << " ";
		}
	}
	else
	{
		printPaths(node->left, path, 1 + pathLen);
		printPaths(node->right, path, 1 + pathLen);
	}
}

TreeNode* BinaryTree::getRoot()
{
	return root;
}



void BinaryTree::destroy(TreeNode *root)
{
	if (root != NULL)
	{
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}

BinaryTree::~BinaryTree()
{
	destroy(root);
}

