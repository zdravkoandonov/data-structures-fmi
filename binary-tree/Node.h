#pragma once
struct Node
{
	int data;
	Node *left, *right;
	Node(int data, Node *left = NULL, Node *right) :
		data(data), left(left), right(right)
	{
	}
};

