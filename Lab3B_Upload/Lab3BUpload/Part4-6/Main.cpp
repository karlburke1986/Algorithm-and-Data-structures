#include "BinaryTree.h"
#include <iostream>

using namespace std;

//Karl Burke

int main()
{
	BinaryTree bt = BinaryTree();

	bt.add('f');
	bt.add('z');
	bt.add('g');
	bt.add('a');
	bt.add('c');
	bt.add('n');
	bt.add('b');
	bt.add('e');
	bt.add('i');

	cout << bt.Search('q') << endl;

	cout << bt.Search('e') << endl;

	bt.Print();


	system("PAUSE");

	return 0;
}