#include "BinaryTree.h"
#include <iostream>

using namespace std;

//Karl Burke

int main()
{
	BinaryTree<char> bt = BinaryTree<char>();

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

	BinaryTree<int> bt1 = BinaryTree<int>();

	bt1.add(8);
	bt1.add(17);
	bt1.add(19);
	bt1.add(1);
	bt1.add(6);
	bt1.add(14);
	bt1.add(30);
	bt1.add(24);
	bt1.add(54);

	cout << bt1.Search(99) << endl;

	cout << bt1.Search(14) << endl;

	bt1.Print();

	system("PAUSE");

	return 0;
}

