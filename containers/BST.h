//
// Created by zdravko on 22.01.16.
//

#ifndef CONTAINERS_BST_H
#define CONTAINERS_BST_H

#include "HeterogeneousListContainer.h"
#include "BSTNode.h"

template <class T>
class BST : HeterogeneousListContainer<T> {
    BSTNode<T> *root;
    int itemsCount;

    using Condition = bool (*)(T const&);

public:
    BST() {
        root = nullptr;
        itemsCount = 0;
    }

    bool member(const T& item) {
        BSTNode<T> *currentNode = root;
        while (currentNode != nullptr) {
            if (item == currentNode->data)
                return true;
            else if(item < currentNode->data)
                insertNode = insertNode->left;
            else
                insertNode = insertNode->right;
        }
        return false;
    }

    bool search(Condition) {}

    void addItem(const T item) {
        BSTNode<T> *&insertNode = root, *parent = nullptr;
        while (insertNode != nullptr) {
            parent = insertNode;
            if (item <= currentNode->data)
                insertNode = insertNode->left;
            else
                insertNode = insertNode->right;
        }
        insertNode = new BSTNode<T>(item, parent);
    }

    void removeAt(BSTNode<T> *node) {
        if (node->parent->left == node)
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;
    }

    void removeItem() {}

    void removeMatching(Condition) {}

    void print() {}

    int size() {}

    void sort() {}

    DoublyLinkedListNode<T>* begin() const {}

    void write(std::ofstream&) {}
};

template<class T>
ostream& operator<<(ostream& os, const BST<T> &l) {
    os << "- ";
    for(DoublyLinkedListNode<T> *node = l.begin(); node != nullptr; node = node->next)
        os << node->data << " - ";
    return os << std::endl;
}


#endif //CONTAINERS_BST_H
