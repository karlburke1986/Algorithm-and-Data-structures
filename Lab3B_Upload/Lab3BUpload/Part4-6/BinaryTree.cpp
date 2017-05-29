#include "BinaryTree.h"
#include <stddef.h>
#include <iostream>

using namespace std;

//Karl Burke

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	destroy(root);
}



/***************************************************************************************

*    Usage: Modified
*    Title: N/A
*    Author: dhayden
*    Date: 23/02/2017
*    Code version: N/A
*    Availability: http://www.cplusplus.com/forum/general/148926/
*
***************************************************************************************/

bool BinaryTree::Search(char value)
{
	if (root == NULL)
	{
		return false;
	}
	else 
	{
		return Search(value, root);
	}
}

bool BinaryTree::Search(char value, TreeNode *node)
{
	if (value == node->data)
	{
		return true;
	}
	else if (value < node->data)
	{
		if (node->left == NULL)
		{
			return false;
		}
		else
		{
			return Search(value, node->left);
		}
	}
	else if (value > node->data)
	{
		if (node->right == NULL)
		{
			return false;
		}
		else
		{
			return Search(value, node->right);
		}
	}

	return false;
}

void BinaryTree::add(char value)
{
	TreeNode *temp = new TreeNode(value);
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
*    Author: hankaixyz
*    Date: 23/02/2017
*    Code version: N/A
*    Availability: http://stackoverflow.com/questions/8183985/recursive-insertion-of-bst
*
***************************************************************************************/

void BinaryTree::add(TreeNode *newNode, TreeNode *addHere)
{
	if (newNode->data < addHere->data)
	{
		if (addHere->left == NULL)
		{
			addHere->left = newNode;
		}
		else
		{
			add(newNode, addHere->left);
		}
	}
	else if (newNode->data > addHere->data)
	{
		if (addHere->right == NULL)
		{
			addHere->right = newNode;
		}
		else
		{
			add(newNode, addHere->right);
		}
	}
}


/*
I used in-order traversal as it bnegins with the left most node
which in a binary tree would be the lowest value and then works
to the right most node which would be the highest value. I choose
this as it was requested to return the tree in ascending order
*/

/***************************************************************************************

*    Usage: Used
*    Title: Binary search tree inorder traversal help
*    Author: matix85
*    Date: 23/02/2017
*    Code version: N/A
*    Availability: http://www.cplusplus.com/forum/general/148926/
*
***************************************************************************************/

void BinaryTree::Print()
{

	Print(root);

}

void BinaryTree::Print(TreeNode *node)
{
	if (node != NULL)
	{
		Print(node->left);
		cout << node->data;
		Print(node->right);
	}
}

void BinaryTree::destroy(TreeNode * node)
{
	if (node != NULL)
	{
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}