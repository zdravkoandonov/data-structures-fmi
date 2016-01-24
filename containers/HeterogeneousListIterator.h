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
    bool mode; // true: whole-container-items-first, false: containers-first-items-first

public:
    HeterogeneousListIterator() {
        // creates an invalid iterator
        nodes.push_back(nullptr);
        currentNodeIterator = nodes.begin();
    }

    HeterogeneousListIterator(HeterogeneousList<T> &heterogeneousList, bool mode) : mode(mode) {
        for (auto it = heterogeneousList.containers.begin(); it != heterogeneousList.containers.end(); ++it)
            nodes.push_back((*it)->begin());

        currentNodeIterator = nodes.begin();
    }

    T& operator*() {
        return (*currentNodeIterator)->data;
    }

    HeterogeneousListIterator &operator++() {
        if (mode) {
            *currentNodeIterator = (*currentNodeIterator)->next;
            if ((*currentNodeIterator) == nullptr) {
                ++currentNodeIterator;
            }
        }
        else {
            if ((*currentNodeIterator) != nullptr)
                *currentNodeIterator = (*currentNodeIterator)->next;
            ++currentNodeIterator;
            if (currentNodeIterator == nodes.end())
                currentNodeIterator = nodes.begin();

            while (currentNodeIterator != nodes.end() && (*currentNodeIterator) == nullptr)
                ++currentNodeIterator;
        }

        return *this;
    }

    operator bool() {
        return currentNodeIterator != nodes.end() && (*currentNodeIterator) != nullptr;
    }
};

template <class T>
class SortedHeterogeneousListIterator {
    list<DoublyLinkedListNode<T>*> nodes;
    typename list<DoublyLinkedListNode<T>*>::iterator currentNodeIterator;

public:
    SortedHeterogeneousListIterator() {
        // creates an invalid iterator
        nodes.push_back(nullptr);
        currentNodeIterator = nodes.begin();
    }

    SortedHeterogeneousListIterator(HeterogeneousList<T> &heterogeneousList) {
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

    SortedHeterogeneousListIterator &operator++() {
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
