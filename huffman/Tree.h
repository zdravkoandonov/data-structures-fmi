//
// Created by zdravkoandonov on 26.12.15.
//

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <list>
#include <ostream>

using std::list;
using std::ostream;

class Tree {
    int occurrences;
    Tree *left, *right;
public:
    Tree(int occurrences);
    Tree(Tree&, Tree&);
    bool operator<(const Tree&) const;
    friend ostream& operator<<(ostream&, const Tree&);
};


#endif //HUFFMAN_TREE_H
