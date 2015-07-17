#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
	BinaryTree tree(10);
	tree.add(11);
	tree.add(5);
	tree.add(7);
	tree.add(8);
	tree.add(9);
	tree.add(6);
	tree.add(4);
	tree.add(3);
	tree.add(12);
	tree.add(9);
	tree.add(9);
	tree.add(9);

	tree.print();

	cout << tree.find(3)->data << " " << tree.find(0) << endl;

	tree.remove(10);

	tree.print();

	cin.get();

	return 0;
}