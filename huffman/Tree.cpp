//
// Created by zdravkoandonov on 26.12.15.
//

#include "Tree.h"

Tree::Tree(int occurrences, char symbol) : occurrences(occurrences), symbol(symbol) {
    left = NULL;
    right = NULL;
}

Tree::Tree(Tree &tree1, Tree &tree2) {
    occurrences = tree1.occurrences + tree2.occurrences;
    symbol = '\0';
    left = &tree1;
    right = &tree2;
}

ostream &operator<<(ostream &out, const Tree &tree) {
    out << tree.occurrences << " (";
    if (tree.left != NULL)
        out << *(tree.left);
    if (tree.right != NULL)
        out << *(tree.right);
    out << ") ";

    return out;
}
