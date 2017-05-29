#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main()
{
	BinaryTree bt = BinaryTree();

	cout << "Height :" << bt.height() << endl;

	bt.add(4);

	cout << "Height :" << bt.height() << endl;

	bt.add(3);
	bt.add(8);
	bt.add(20);
	bt.add(9);
	bt.add(2);
	bt.add(3);
	bt.add(7);

	cout << "Height :" << bt.height() << endl;

	cout << bt.hasPathSum(bt.getRoot(), 9) << endl;

	cout << bt.hasPathSum(bt.getRoot(), 2) << endl;
	
	bt.printPaths(bt.getRoot());

	system("PAUSE");

	return 0;
}