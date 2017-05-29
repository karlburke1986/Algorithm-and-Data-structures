#include <stddef.h>
#include <iostream>

using namespace std;

//Karl Burke

template<typename T> class TreeNode
{	
public:
	TreeNode();
	TreeNode(T);
	~TreeNode();
	T data;
	TreeNode<T> *left;
	TreeNode<T> *right;
};

template<typename T> class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	bool Search(T);
	void add(T);
	void Print();
private:
	TreeNode<T> *root;
	void destroy(TreeNode<T>*);
	void add(TreeNode<T>*, TreeNode<T>*);
	bool Search(T, TreeNode<T>*);
	void Print(TreeNode<T>*);
};

template<typename T>TreeNode<T>::TreeNode()
{
	data = NULL;
	left = NULL;
	right = NULL;
}

template<typename T>TreeNode<T>::TreeNode(T value)
{
	data = value;
	left = NULL;
	right = NULL;
}

template<typename T>TreeNode<T>::~TreeNode()
{
}

template<typename T>BinaryTree<T>::BinaryTree()
{
	root = NULL;
}

template<typename T>BinaryTree<T>::~BinaryTree()
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

template<typename T>bool BinaryTree<T>::Search(T value)
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

template<typename T>bool BinaryTree<T>::Search(T value, TreeNode<T> *node)
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

template<typename T>void BinaryTree<T>::add(T value)
{
	TreeNode<T> *temp = new TreeNode<T>(value);
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

template<typename T>void BinaryTree<T>::add(TreeNode<T> *newNode, TreeNode<T> *addHere)
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

/***************************************************************************************

*    Usage: Used
*    Title: Binary search tree inorder traversal help
*    Author: matix85
*    Date: 23/02/2017
*    Code version: N/A
*    Availability: http://www.cplusplus.com/forum/general/148926/
*
***************************************************************************************/

template<typename T>void BinaryTree<T>::Print()
{

	Print(root);

}

template<typename T>void BinaryTree<T>::Print(TreeNode<T> *node)
{
	if (node != NULL)
	{
		Print(node->left);
		cout << node->data << " ";
		Print(node->right);
	}
}

template<typename T>void BinaryTree<T>::destroy(TreeNode<T> * node)
{
	if (node != NULL)
	{
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

