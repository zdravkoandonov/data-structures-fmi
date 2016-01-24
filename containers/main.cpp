#include <iostream>
#include "DoublyLinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "HeterogeneousList.h"
#include "HeterogeneousListIterator.h"

using std::cout;
using std::endl;

int main() {
    int x = 10;
    DoublyLinkedList<int> l;
    l.insertFront(1);
    l.insertFront(2);
    l.insertFront(3);
    l.insertFront(4);
    l.insertFront(5);
    l.insertFront(16);
    DoublyLinkedListNode<int> *p = l.begin();
    p = p->next;
    l.removeAt(p);
    p = l.end();
    l.insertAfter(p->prev, 10);
    l.insertBefore(l.begin()->next->next, 17);

    cout << l; // 16 4 17 3 2 10 1
    cout << l.member(x) << endl; // 1
    l.sort();
    cout << l; // 1 2 3 4 10 16 17

    Queue<int> q;
    cout << q.empty() << endl; // 1
    q.queue(1);
    q.queue(2);
    q.queue(3);
    q.queue(4);
    q.queue(5);
    q.dequeue();
    cout << q.front() << endl; // 2
    cout << q.empty() << endl; // 0
    cout << q; // 5 4 3 2

    Stack<int> s;
    cout << s.empty() << endl; // 1
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    cout << s.top() << endl; // 4
    cout << s.empty() << endl; // 0
    cout << s; // 4 3 2 1

    ifstream input("numbers");
    HeterogeneousList<int> hetList(input);
    input.close();

    ofstream outputRawTest("numbers.out");
    hetList.writeOut(outputRawTest);
    outputRawTest.close();

    cout << hetList.member(3) << endl; // 1
    cout << hetList.member(0) << endl; // 0
    hetList.print();
    cout << endl;
    hetList.addItemLoadBalanced(10);
    hetList.addItemLoadBalanced(11);
    hetList.addItemLoadBalanced(12);
    hetList.addItemLoadBalanced(13);
    hetList.addItemLoadBalanced(14);
    hetList.addItemLoadBalanced(15);
    hetList.addItemLoadBalanced(16);
    hetList.print();

    cout << hetList.search([](int const& item) { return item % 16 == 0; }) << endl;

    hetList.sortEachContainer();
    hetList.print();

    hetList.removeMatching([](int const &item) { return item % 2 == 1; });
    hetList.print();

    SortedHeterogeneousListIterator<int> hetListIt(hetList);
    for (; hetListIt; ++hetListIt)
        cout << *hetListIt << " ";
    cout << endl;

    if (auto it = hetList.findInSorted(4))
        cout << *it << endl;
    else
        cout << "Not found" << endl;

    ofstream output("numbers-changed.out");
    hetList.writeOut(output);
    output.close();

    ifstream in("numbers-changed.out");
    HeterogeneousList<int> hetList2(in);
    hetList2.print();
    in.close();

    HeterogeneousListIterator<int> hetListIt1(hetList, true);
    HeterogeneousListIterator<int> hetListIt2(hetList, false);
    for (; hetListIt1; ++hetListIt1)
        cout << *hetListIt1 << " ";
    cout << endl;
    for (;hetListIt2; ++hetListIt2)
        cout << *hetListIt2 << " ";
    cout << endl;

    return 0;
}