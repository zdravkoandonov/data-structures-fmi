//
// Created by zdravkoandonov on 25.12.15.
//

#include <queue>
#include "Huffman.h"

using std::priority_queue;
using std::vector;

map<char, int> Huffman::buildOccurrenceTable(string input) {
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

Tree& Huffman::buildTree(map<char, int> &table) {
    priority_queue<Tree*, vector<Tree*>, TreeComparison> trees;
    auto tableIterator = table.begin();
    for (; tableIterator != table.end(); tableIterator++) {
        trees.push(new Tree(tableIterator->second, tableIterator->first));
    }
    while (trees.size() > 1) {
        Tree *tree1 = trees.top();
        trees.pop();
        Tree *tree2 = trees.top();
        trees.pop();

        trees.push(new Tree(*tree1, *tree2));
    }

    return *trees.top();
}

void dfs(Tree *tree, int depth, string currentCode, map<char, string> &codeTable) {
    if (tree) {
        if (tree->left && tree->right) {
            dfs(tree->left, depth + 1, currentCode + '0', codeTable);
            dfs(tree->right, depth + 1, currentCode + '1', codeTable);
        }
        else {
            codeTable.insert(pair<char, string>(tree->symbol, currentCode));
        }
    }
}

map<char, string> Huffman::buildCodeTable(Tree &tree) {
    map<char, string> codeTable;
    dfs(&tree, 0, "", codeTable);
    return  codeTable;
}
