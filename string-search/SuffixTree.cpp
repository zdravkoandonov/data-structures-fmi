#include "SuffixTree.h"
#include <iostream>

using std::cout;
using std::endl;

SuffixTree::SuffixTree(char *str, int length) : length(length)
{
	this->str = new char[length];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}

	const int END = -1;

	root = new Node(Substring(END, END), map<char, Node*>());

	Node *activeNode = root;
	char activeEdge = '\0';
	int activeLength = 0, remainder = 1;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < remainder; j++)
		{
			if (root->descendants[str[i]] == NULL)
			{
				// no suffix starts with str[i] -> insert new suffix
				root->descendants[str[i]] = new Node(Substring(i, END));
			}
			else if (str[root->descendants[str[i]]->substr.begin+activeLength] == str[i])
			{
				activeNode = root;
				activeEdge = str[i];
				activeLength++;
				remainder++;
			}
			else
			{
				// split
				map<char, Node*> tempMap = map<char, Node*>();
				tempMap[str[activeNode->descendants[str[i]]->substr.begin + remainder]] = new Node(
					Substring(activeNode->descendants[str[i]]->substr.begin + remainder, activeNode->descendants[str[i]]->substr.end));
				tempMap[str[i]] = new Node(Substring(i, END));

				Node *toDel = activeNode->descendants[str[i]];

				activeNode->descendants[str[i]] = new Node(
					Substring(activeNode->descendants[str[i]]->substr.begin, activeNode->descendants[str[i]]->substr.begin + remainder - 1),
					tempMap);

				delete toDel;
			}
		}
	}
}


SuffixTree::~SuffixTree()
{
}

void SuffixTree::print()
{
	print(root, 0);
}

void SuffixTree::print(Node *root, int depth)
{
	for (int i = root->substr.begin; i <= (root->substr.end == -1) ? length-1 : root->substr.end; i++)
	{
		cout << str[i];
	}
	cout << endl;
	for (map<char, Node*>::iterator i = root->descendants.begin(); i != root->descendants.end(); i++)
	{
		print(i->second, depth+1);
	}
}
