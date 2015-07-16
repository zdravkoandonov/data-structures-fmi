#pragma once
#include "Node.h"

class BinaryTree
{
	Node *root;
public:
	BinaryTree(int rootData);
	~BinaryTree();
	void add(int);
};

