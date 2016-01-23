//
// Created by zdravko on 22.01.16.
//

#ifndef CONTAINERS_DOUBLYLINKEDLIST_H
#define CONTAINERS_DOUBLYLINKEDLIST_H

#include <ostream>
#include "HeterogeneousListContainer.h"
#include "DoublyLinkedListNode.h"

using std::ostream;

template <class T>
class DoublyLinkedList : public HeterogeneousListContainer<T> {
    DoublyLinkedListNode<T> *front;
    DoublyLinkedListNode<T> *back;
    int itemsCount;

    using Condition = bool (*)(T const&);

public:
    DoublyLinkedList() {
        front = nullptr;
        back = nullptr;
        itemsCount = 0;
    }

    DoublyLinkedListNode<T> *begin() const {
        return front;
    }

    DoublyLinkedListNode<T> *end() const {
        return back;
    }

    bool empty() {
        return front == nullptr;
    }

    bool insertAfter(DoublyLinkedListNode<T> *node, const T item) {
        if (empty()) {
            front = back = new DoublyLinkedListNode<T>(item);
            itemsCount++;
            return true;
        }

        if (node == nullptr)
            return false;

        DoublyLinkedListNode<T>* p = new DoublyLinkedListNode<T>(item, node, node->next);
        p->prev->next = p;
        if (back == node)
            back = p;
        else
            p->next->prev = p;

        itemsCount++;
        return true;
    }

    bool insertBefore(DoublyLinkedListNode<T> *node, const T item) {
        if (empty()) {
            back = front = new DoublyLinkedListNode<T>(item);
            itemsCount++;
            return true;
        }

        if (node == nullptr)
            return false;

        DoublyLinkedListNode<T> *p = new DoublyLinkedListNode<T>(item, node->prev, node);
        p->next->prev = p;
        if (front == node)
            front = p;
        else
            p->prev->next = p;

        itemsCount++;
        return true;
    }

    bool insertFront(const T item) {
        itemsCount++;
        return insertBefore(front, item);
    }

    bool insertBack(const T item) {
        itemsCount++;
        return insertAfter(back, item);
    }

    void removeAt(DoublyLinkedListNode<T> *node) {
        if (front == node) {
            front = node->next;
        }
        else if (back == node) {
            back = node->prev;
        }

        if (node->prev != nullptr)
            node->prev->next = node->next;
        if (node->next != nullptr)
            node->next->prev = node->prev;

        delete node;
        itemsCount--;
    }

    bool member(const T& x) {
        if (empty()) {
            return false;
        }
        else
        {
            DoublyLinkedListNode<T> *currentNode = front;
            while (currentNode != nullptr) {
                if (currentNode->data == x) {
                    return true;
                }
                else {
                    currentNode = currentNode->next;
                }
            }
            return false;
        }
    }

    bool search(Condition predicate) {
        if (empty()) {
            return false;
        }
        else
        {
            DoublyLinkedListNode<T> *currentNode = front;
            while (currentNode != nullptr) {
                if ((*predicate)(currentNode->data)) {
                    return true;
                }
                else {
                    currentNode = currentNode->next;
                }
            }
            return false;
        }
    }

    void addItem(const T item) {
        insertBack(item);
    }

    void removeItem() {
        removeAt(end());
    }

    void print() {
        std::cout << *this;
    }

    int size() {
        return itemsCount;
    }
};

template<class T>
ostream& operator<<(ostream& os, const DoublyLinkedList<T> &l) {
    os << "- ";
    for(DoublyLinkedListNode<T> *node = l.begin(); node != nullptr; node = node->next)
        os << node->data << " - ";
    return os << std::endl;
}


#endif //CONTAINERS_DOUBLYLINKEDLIST_H
