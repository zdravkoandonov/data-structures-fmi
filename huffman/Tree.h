//
// Created by zdravkoandonov on 26.12.15.
//

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <list>
#include <iostream>

using std::list;
using std::ostream;
using std::istream;

class Tree {
public:
    int occurrences;
    char symbol;
    Tree *left, *right;
    Tree(int, char);
    Tree(Tree&, Tree&);
    friend ostream& operator<<(ostream&, const Tree&);
    friend istream& operator>>(istream&, Tree*&);
};

class TreeComparison
{
public:
    // get the tree with least occurrences on top
    bool operator() (const Tree *tree1, const Tree *tree2) const
    {
        return tree1->occurrences > tree2->occurrences;
    }
};


#endif //HUFFMAN_TREE_H
