#pragma once

#include <map>
#include "Substring.h"
#include "Node.h"

using std::map;

class SuffixTree
{
	char *str;
	int length;
	Node *root;
public:
	SuffixTree(char *str, int length);
	~SuffixTree();
	void print();
	void print(Node *root, int depth);
};
