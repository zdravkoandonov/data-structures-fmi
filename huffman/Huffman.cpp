//
// Created by zdravkoandonov on 25.12.15.
//

#include <queue>
#include "Huffman.h"

using std::priority_queue;

Tree Huffman::buildTree(map<char, int> table) {
    priority_queue<Tree> trees;
    auto tableIterator = table.begin();
    for (; tableIterator != table.end(); tableIterator++) {
        trees.push(Tree(tableIterator->second));
    }
    while (trees.size() > 1) {
        Tree tree1 = trees.top();
        trees.pop();
        Tree tree2 = trees.top();
        trees.pop();

        trees.push(Tree(tree1, tree2));
    }

    return trees.top();
}

map<char, int> Huffman::buildTable(string input) {
    map<char, int> table;
    map<char, int>::iterator tableIterator;
    unsigned long inputSize = input.size();

    for (int i = 0; i < inputSize; i++) {
        if ((tableIterator = table.find(input[i])) != table.end())
            (*tableIterator).second++;
        else
            table.insert(pair<char, int>(input[i], 1));
    }

    return table;
}
