#pragma once
#include "Node.h"

class BinaryTree
{
	Node *root;
public:
	BinaryTree(int rootData);
	~BinaryTree();
	void add(int);
	Node* find(int);
	void remove(int);
	void print();
private:
	void add(Node *&curRoot, int);
	Node* find(Node *curRoot, int);
	void remove(Node *&curRoot, int);
	void print(Node *curRoot);
};

