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

