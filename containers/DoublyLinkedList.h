//
// Created by zdravko on 22.01.16.
//

#ifndef CONTAINERS_DOUBLYLINKEDLIST_H
#define CONTAINERS_DOUBLYLINKEDLIST_H

#include <ostream>
#include <fstream>
#include "HeterogeneousListContainer.h"
#include "DoublyLinkedListNode.h"

using std::ostream;

template <class T>
class DoublyLinkedList : public HeterogeneousListContainer<T> {
    DoublyLinkedListNode<T> *front;
    DoublyLinkedListNode<T> *back;
    int itemsCount;

    using Condition = bool (*)(T const&);

    void copy(const DoublyLinkedList<T> &other) {
        for (DoublyLinkedListNode<T> *it = other.begin(); it != nullptr; it = it->next)
            insertBack(it->data);
    }

    void clean() {
        while (!empty())
            removeAt(end());
    }

    static void split(DoublyLinkedList<T> const& l, DoublyLinkedList<T>& l1, DoublyLinkedList<T>& l2) {
        DoublyLinkedList<T> *first = &l1, *second = &l2;
        for(DoublyLinkedListNode<T> *it = l.begin(); it != nullptr; it = it->next) {
            first->insertBack(it->data);
            std::swap(first, second);
        }
    }

    static void merge(DoublyLinkedList<T> const& l1, DoublyLinkedList<T> const& l2, DoublyLinkedList<T>& l) {
        DoublyLinkedListNode<T> *i1 = l1.begin(), *i2 = l2.begin();
        while (i1 != nullptr && i2 != nullptr) {
            if (i1->data < i2->data) {
                l.insertBack(i1->data);
                i1 = i1->next;
            }
            else {
                l.insertBack(i2->data);
                i2 = i2->next;
            }
        }
        // !i1 || !i2
        while (i1 != nullptr) {
            l.insertBack(i1->data);
            i1 = i1->next;
        }
        while (i2 != nullptr) {
            l.insertBack(i2->data);
            i2 = i2->next;
        }
    }

    DoublyLinkedList<T> mergeSort() {
        if (begin()->next == nullptr)
            return *this;
        // 1. разделяме
        DoublyLinkedList<T> l1, l2;
        split(*this, l1, l2);

        // 2. рекурсивно сортираме
        // 3. сливаме сортираните списъци
        DoublyLinkedList<T> result;
        merge(l1.mergeSort(), l2.mergeSort(), result);
        return result;
    }

public:
    DoublyLinkedList() {
        front = nullptr;
        back = nullptr;
        itemsCount = 0;
    }

    DoublyLinkedList(const DoublyLinkedList<T> &other) {
        front = nullptr;
        back = nullptr;
        itemsCount = 0;

        copy(other);
    }

    DoublyLinkedList& operator=(const DoublyLinkedList<T> &other) {
        if (this != &other) {
            clean();
            copy(other);
        }
        return *this;
    }

    ~DoublyLinkedList() {
        clean();
    }

    HeterogeneousListContainer<T> *clone() const {
        return new DoublyLinkedList<T>(*this);
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
        if (back == node) {
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

    void removeMatching(Condition predicate) {
        DoublyLinkedListNode<T> *toDel = nullptr;
        DoublyLinkedListNode<T> *it = begin();
        while (it != nullptr) {
            if ((*predicate)(it->data))
                toDel = it;

            it = it->next;

            if (toDel != nullptr) {
                removeAt(toDel);
                toDel = nullptr;
            }
        }
    }

    void addItem(const T item) {
        insertBack(item);
    }

    void removeItem() {
        removeAt(begin());
    }

    void print() {
        std::cout << *this;
    }

    int size() {
        return itemsCount;
    }

    void sort() {
        *this = mergeSort();
    }

    void write(std::ofstream &output) {
        output << "0 ";
        for (auto it = begin(); it != nullptr; it = it->next) {
            output << it->data << ' ';
        }
        output << std::endl;
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
