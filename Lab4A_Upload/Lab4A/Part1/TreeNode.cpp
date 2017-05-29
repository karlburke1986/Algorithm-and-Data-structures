#include "TreeNode.h"
#include <stddef.h>

//Karl Burke

TreeNode::TreeNode()
{
	data = NULL;
	left = NULL;
	right = NULL;
}

TreeNode::TreeNode(char value)
{
	data = value;
	left = NULL;
	right = NULL;
}

TreeNode::~TreeNode()
{
}
