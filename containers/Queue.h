//
// Created by zdravko on 22.01.16.
//

#ifndef CONTAINERS_QUEUE_H
#define CONTAINERS_QUEUE_H

#include "DoublyLinkedList.h"

template <class T>
class Queue : public HeterogeneousListContainer<T> {
    DoublyLinkedList<T> container;

    using Condition = bool (*)(T const&);

public:
    Queue() {
        container = DoublyLinkedList<T>();
    }

    void queue(const T item) {
        container.insertFront(item);
    }

    T front() {
        return container.end()->data;
    }

    bool empty() {
        return container.empty();
    }

    bool dequeue() {
        if (empty())
            return false;

        container.removeAt(container.end());
        return true;
    }

    bool member(const T &item) {
        return container.member(item);
    }

    bool search(Condition predicate) {
        return  container.search(predicate);
    }

    void addItem(const T item) {
        queue(item);
    }

    void removeItem() {
        dequeue();
    }

    void print() {
        std::cout << *this;
    }

    int size() {
        return container.size();
    }

    template <class P> friend ostream& operator<<(ostream&, const Queue<P>&);
};

template<class T>
ostream& operator<<(ostream& os, const Queue<T> &l) {
    os << "> ";
    for(DoublyLinkedListNode<T> *node = l.container.begin(); node != nullptr; node = node->next)
        os << node->data << " > ";
    return os << std::endl;
}


#endif //CONTAINERS_QUEUE_H
