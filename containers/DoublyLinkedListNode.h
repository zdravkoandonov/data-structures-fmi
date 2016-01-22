//
// Created by zdravko on 22.01.16.
//

#ifndef CONTAINERS_DOUBLYLINKEDLISTNODE_H
#define CONTAINERS_DOUBLYLINKEDLISTNODE_H

template <class T>
struct DoublyLinkedListNode {
    T data;
    DoublyLinkedListNode *prev, *next;

    DoublyLinkedListNode(T data, DoublyLinkedListNode *prev = nullptr, DoublyLinkedListNode *next = nullptr)
            : data(data), prev(prev), next(next) { }
};


#endif //CONTAINERS_DOUBLYLINKEDLISTNODE_H
