//
// Created by zdravkoandonov on 26.12.15.
//

#include "Tree.h"

Tree::Tree(int occurrences, char symbol) : occurrences(occurrences), symbol(symbol) {
    left = nullptr;
    right = nullptr;
}

Tree::Tree(Tree &tree1, Tree &tree2) {
    occurrences = tree1.occurrences + tree2.occurrences;
    symbol = '\0';
    left = &tree1;
    right = &tree2;
}

ostream &operator<<(ostream &outputStream, const Tree &tree) {
    outputStream << tree.occurrences << " ";
    if (tree.symbol != '\0') {
        outputStream << "'" << tree.symbol << " ";
    }
    else {
        outputStream << *(tree.left);
        outputStream << *(tree.right);
    }

    return outputStream;
}

istream &operator>>(istream &inputStream, Tree *&tree) {
    char symbol;
    int occurrences;
    if (!inputStream.eof()) {
        inputStream >> occurrences;
        inputStream.ignore();
        if (inputStream.peek() == '\'') {
            inputStream.ignore();
            inputStream >> symbol;
            tree = new Tree(occurrences, symbol);
        }
        else {
            tree = new Tree(occurrences, '\0');
            inputStream >> tree->left >> tree->right;
        }
    }

    return inputStream;
}