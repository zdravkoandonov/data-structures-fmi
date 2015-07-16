#pragma once
struct Node
{
	int data;
	Node *next;
	Node(int data, Node *next = NULL) :
		data(data), next(next)
	{
	}
};

