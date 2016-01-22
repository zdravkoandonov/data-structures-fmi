//
// Created by zdravko on 22.01.16.
//

#ifndef CONTAINERS_HETEROGENEOUSLIST_H
#define CONTAINERS_HETEROGENEOUSLIST_H

#include <list>
#include <fstream>
#include <string>
#include <sstream>
#include "HeterogeneousListContainer.h"

using std::list;
using std::ifstream;
using std::string;
using std::istringstream;

template <class T>
class HeterogeneousList {
    list<HeterogeneousListContainer<T>*> containers;
public:
    HeterogeneousList(ifstream &input) {
        int containerType, tempNumber;
        string lineString;
        HeterogeneousListContainer<T> *container;
        while (getline(input, lineString)) {
            istringstream lineStream(lineString);
            lineStream >> containerType;
            switch (containerType) {
                case 0:
                    container = new DoublyLinkedList<T>();
                    break;
                case 1:
                    container = new Queue<T>();
                    break;
                case 2:
                    container = new Stack<T>();
                    break;
            }
            while (lineStream >> tempNumber)
                container->addItem(tempNumber);

            containers.push_back(container);
        }
    }

    bool member(const T &x) {
        for (auto it = containers.begin(); it != containers.end(); ++it) {
            if ((*it)->member(x))
                return true;
        }
        return false;
    }
};


#endif //CONTAINERS_HETEROGENEOUSLIST_H
