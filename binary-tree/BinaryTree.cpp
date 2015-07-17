#include <iostream>
#include "BinaryTree.h"

using std::cout;

BinaryTree::BinaryTree(int rootData)
{
	root = new Node(rootData);
}


BinaryTree::~BinaryTree()
{
}

void BinaryTree::add(int data)
{
	add(root, data);
}

void BinaryTree::add(Node *&curRoot, int data)
{
	if (curRoot == NULL)
		curRoot = new Node(data);
	else if (data > curRoot->data)
		add(curRoot->right, data);
	else
		add(curRoot->left, data);
}

Node* BinaryTree::find(int data)
{
	return find(root, data);
}

Node* BinaryTree::find(Node *curRoot, int data)
{
	if (curRoot == NULL || curRoot->data == data)
		return curRoot;

	if (data > curRoot->data)
		return find(curRoot->right, data);
	else
		return find(curRoot->left, data);
}

void BinaryTree::remove(int data)
{
	remove(root, data);
}

void BinaryTree::remove(Node *&curRoot, int data)
{
	if (curRoot != NULL)
	{
		if (data > curRoot->data)
			remove(curRoot->right, data);
		else if (data < curRoot->data)
			remove(curRoot->left, data);
		else
			if (curRoot->left != NULL && curRoot->right != NULL)
			{
				Node *maxSmaller = curRoot->left;
				while (maxSmaller->right != NULL)
				{
					maxSmaller = maxSmaller->right;
				}
				int numToReplace = maxSmaller->data;
				remove(curRoot->left, numToReplace);
				curRoot->data = numToReplace;
			}
			else if (curRoot->left != NULL)
			{
				Node *toDel = curRoot;
				curRoot = curRoot->left;
				delete toDel;
			}
			else if (curRoot->right != NULL)
			{
				Node *toDel = curRoot;
				curRoot = curRoot->right;
				delete toDel;
			}
			else
			{
				delete curRoot;
				curRoot = NULL;
			}
	}
}

void BinaryTree::print()
{
	if (root != NULL)
		print(root);
}

void BinaryTree::print(Node *curRoot)
{
	if (curRoot->left != NULL)
	{
		print(curRoot->left);
	}
	cout << curRoot->data << " ";
	if (curRoot->right != NULL)
	{
		print(curRoot->right);
	}
}

