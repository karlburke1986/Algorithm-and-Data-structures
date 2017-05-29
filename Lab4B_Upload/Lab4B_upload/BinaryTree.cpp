#include "BinaryTree.h"
#include <stddef.h>
#include <iostream>

using namespace std;

//Karl Burke

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

/***************************************************************************************

*    Usage: Used
*    Title: A program to check if a binary tree is BST or not
*    Author: N/A
*    Date: 05/03/2017
*    Code version: N/A
*    Availability: http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
*
***************************************************************************************/

bool BinaryTree::isBSTV1(TreeNode *node)
{
	if (node == NULL)
	{
		return true;
	}

	if (node->left != NULL && maxValue(node->left) > node->data)
	{
		return false;
	}

	if (node->right != NULL && minValue(node->right) < node->data)
	{
		return false;
	}

	if (!isBSTV1(node->left) || !isBSTV1(node->right))
	{
		return false;
	}

	return true;
}

/***************************************************************************************

*    Usage: Used
*    Title: A program to check if a binary tree is BST or not
*    Author: N/A
*    Date: 05/03/2017
*    Code version: N/A
*    Availability: http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
*
***************************************************************************************/

bool BinaryTree::isBSTV2(TreeNode *node)
{
	return isBSTV2(node, INT_MIN, INT_MAX);
}

bool BinaryTree::isBSTV2(TreeNode *node, int min, int max)
{
	if (node == NULL)
	{
		return true;
	}

	if (node->data < min || node->data > max)
	{
		return false;
	}

	return isBSTV2(node->left, min, node->data) &&
		isBSTV2(node->right, node->data, max);
}

/***************************************************************************************

*    Usage: Modified
*    Title: Node with minimum value in a Binary Search Tree
*    Author: invalid_id
*    Date: 05/03/2017
*    Code version: N/A
*    Availability: http://stackoverflow.com/questions/21109677/node-with-minimum-value-in-a-binary-search-tree
*
***************************************************************************************/

int BinaryTree::minValue(TreeNode *node)
{
	if (root == NULL)
	{
		return -1;
	}
	else if (node->left == NULL)
	{
		return node->data;
	}
	else
	{
		return minValue(node->left);
	}

}

int BinaryTree::maxValue(TreeNode *node)
{
	if (root == NULL)
	{
		return -1;
	}
	else if (node->right == NULL)
	{
		return node->data;
	}
	else
	{
		return maxValue(node->right);
	}
}

TreeNode * BinaryTree::getRoot()
{
	return root;
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

//http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/

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

