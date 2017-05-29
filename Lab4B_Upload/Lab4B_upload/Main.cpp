#include "BinaryTree.h"
#include <iostream>

using namespace std;

//Karl Burke

int main()
{
	BinaryTree bt = BinaryTree();

	cout << bt.minValue(bt.getRoot());

	bt.add(5);
	bt.add(7);
	bt.add(9);
	bt.add(3);
	bt.add(2);

	cout << bt.minValue(bt.getRoot()) << endl;

	cout << bt.maxValue(bt.getRoot()) << endl;

	cout << bt.isBSTV1(bt.getRoot()) << endl;

	cout << bt.isBSTV2(bt.getRoot()) << endl;

	system("PAUSE");

	return 0;
}