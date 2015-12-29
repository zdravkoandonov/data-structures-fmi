//
// Created by zdravkoandonov on 26.12.15.
//

#include "Tree.h"

Tree::Tree(int occurrences) : occurrences(occurrences) {
    left = NULL;
    right = NULL;
}

Tree::Tree(Tree &tree1, Tree &tree2) {
    occurrences = tree1.occurrences + tree2.occurrences;
    left = &tree1;
    right = &tree2;
}

bool Tree::operator<(const Tree &other) const {
    return occurrences < other.occurrences;
}

ostream &operator<<(ostream &out, const Tree &tree) {
    out << tree.occurrences << " ";
    if (tree.left != NULL)
        out << *(tree.left);
    if (tree.right != NULL)
        out << *(tree.right);

    return out;
}
