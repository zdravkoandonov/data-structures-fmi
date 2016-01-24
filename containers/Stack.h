//
// Created by zdravko on 22.01.16.
//

#ifndef CONTAINERS_STACK_H
#define CONTAINERS_STACK_H

#include "DoublyLinkedList.h"

template <class T>
class Stack : public HeterogeneousListContainer<T> {
    DoublyLinkedList<T> container;

    using Condition = bool (*)(T const&);

public:
    Stack() {
        container = DoublyLinkedList<T>();
    }

    HeterogeneousListContainer<T> *clone() const {
        return new Stack<T>(*this);
    }

    DoublyLinkedListNode<T> *begin() const {
        return container.begin();
    }

    void push(const T item) {
        container.insertFront(item);
    }

    T top() {
        return container.begin()->data;
    }

    bool empty() {
        return container.empty();
    }

    bool pop() {
        if (empty())
            return false;

        container.removeAt(container.begin());
        return true;
    }

    bool member(const T &item) {
        return container.member(item);
    }

    bool search(Condition predicate) {
        return  container.search(predicate);
    }

    void removeMatching(Condition predicate) {
        container.removeMatching(predicate);
    }

    void addItem(const T item) {
        push(item);
    }

    void removeItem() {
        pop();
    }

    void print() {
        std::cout << *this;
    }

    int size() {
        return container.size();
    }

    void sort() {
        container.sort();
    }

    void write(std::ofstream &output) {
        output << "2 ";
        for (auto it = container.end(); it != nullptr; it = it->prev) {
            output << it->data << ' ';
        }
        output << std::endl;
    }

    template <class P> friend ostream& operator<<(ostream&, const Stack<P>&);
};

template<class T>
ostream& operator<<(ostream& os, const Stack<T> &l) {
    for(DoublyLinkedListNode<T> *node = l.container.begin(); node != nullptr; node = node->next)
        os << node->data << ' ';
    return os << ']' << std::endl;
}


#endif //CONTAINERS_STACK_H
