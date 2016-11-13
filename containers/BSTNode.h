//
// Created by zdravko on 24.01.16.
//

#ifndef CONTAINERS_BSTNODE_H
#define CONTAINERS_BSTNODE_H

template <class T>
struct BSTNode {
    T data;
    BSTNode *parent, *left, *right;

    BSTNode(T data, BSTNode *parent = nullptr, BSTNode *left = nullptr, BSTNode *right = nullptr)
            : data(data), parent(parent), left(left), right(right) {}
};


#endif //CONTAINERS_BSTNODE_H
