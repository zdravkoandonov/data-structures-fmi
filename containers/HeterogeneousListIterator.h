//
// Created by zdravko on 23.01.16.
//

#ifndef CONTAINERS_HETEROGENEOUSLISTITERATOR_H
#define CONTAINERS_HETEROGENEOUSLISTITERATOR_H


#include "HeterogeneousList.h"
#include "DoublyLinkedList.h"

template <class T>
class HeterogeneousListIterator {
    list<DoublyLinkedListNode<T>*> nodes;
    typename list<DoublyLinkedListNode<T>*>::iterator currentNodeIterator;

public:
    HeterogeneousListIterator() {
        // creates an invalid iterator
        nodes.push_back(nullptr);
        currentNodeIterator = nodes.begin();
    }

    HeterogeneousListIterator(HeterogeneousList<T> &heterogeneousList) {
        auto it = heterogeneousList.containers.begin();
        nodes.push_back((*it)->begin());
        ++it;
        currentNodeIterator = nodes.begin();
        for (; it != heterogeneousList.containers.end(); ++it) {
            nodes.push_back((*it)->begin());
            if ((*it)->begin()->data < (*currentNodeIterator)->data) {
                currentNodeIterator = --nodes.end();
            }
        }
    }

    T& operator*() {
        return (*currentNodeIterator)->data;
    }

    HeterogeneousListIterator &operator++() {
        *currentNodeIterator = (*currentNodeIterator)->next;

        currentNodeIterator = nodes.begin();
        auto it = ++nodes.begin();
        for (; it != nodes.end(); ++it) {
            if ((*currentNodeIterator) == nullptr) {
                currentNodeIterator = it;
            }
            else if ((*it) != nullptr && (*it)->data < (*currentNodeIterator)->data) {
                currentNodeIterator = it;
            }
        }

        return *this;
    }

    operator bool() {
        return (*currentNodeIterator) != nullptr;
    }
};


#endif //CONTAINERS_HETEROGENEOUSLISTITERATOR_H
