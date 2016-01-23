//
// Created by zdravko on 22.01.16.
//

#ifndef CONTAINERS_HETEROGENEOUSLISTITEM_H
#define CONTAINERS_HETEROGENEOUSLISTITEM_H

#include <fstream>
#include "DoublyLinkedListNode.h"

template <class T>
class HeterogeneousListContainer {
    using Condition = bool (*)(T const&);

public:
    virtual bool member(const T&) = 0;
    virtual bool search(Condition) = 0;
    virtual void addItem(const T) = 0;
    virtual void removeItem() = 0;
    virtual void removeMatching(Condition) = 0;
    virtual void print() = 0;
    virtual int size() = 0;
    virtual void sort() = 0;
    virtual DoublyLinkedListNode<T>* begin() const = 0;
    virtual void write(std::ofstream&) = 0;
};


#endif //CONTAINERS_HETEROGENEOUSLISTITEM_H
