#pragma once

#include <map>
#include "Substring.h"

using std::map;

struct Node
{
	Substring substr;
	map<char, Node*> descendants;
	Node *suffixLink;

	Node(Substring substr = Substring(), map<char, Node*> descendants = map<char, Node*>(), Node *suffixLink = NULL) : 
		substr(substr), descendants(descendants), suffixLink(suffixLink)
	{
	}

	~Node()
	{
	}
};

