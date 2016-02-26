/// Using the binary tree from the lectures

#include <iostream>
#include <list>
#include <queue>

#include "bintree.cpp"

using namespace std;

bool isPrefix(const list<int>& l, queue<int> q) {
    for (int listElement : l) {
        if (q.empty() || listElement != q.front())
            return false;
        q.pop();
    }
    return true;
}

int levelIsPrefix(BinaryTree<int> &tree, queue<int> &q) {
    int currentLevelIndex = 0;
    list<int> currentLevel;
    list<BinaryTreePosition<int> > currentLevelPos, nextLevelPos;
    currentLevelPos.push_back(tree.root());
    currentLevel.push_back(*tree.root());
    while (!currentLevelPos.empty()) {
        if (isPrefix(currentLevel, q))
            return currentLevelIndex;

        currentLevelIndex++;
        currentLevel.clear();
        while (!currentLevelPos.empty()) {
            if (-currentLevelPos.front()) {
                nextLevelPos.push_back(-currentLevelPos.front());
                currentLevel.push_back(*(-currentLevelPos.front()));
            }
            if (+currentLevelPos.front()) {
                nextLevelPos.push_back(+currentLevelPos.front());
                currentLevel.push_back(*(+currentLevelPos.front()));
            }
            currentLevelPos.pop_front();
        }
        currentLevelPos = nextLevelPos;
        nextLevelPos.clear();
    }

    return -1;
}

int main() {
    BinaryTree<int> tree(1,
                         BinaryTree<int>(2, BinaryTree<int>(3), BinaryTree<int>(2)),
                         BinaryTree<int>(2, BinaryTree<int>(1)));
    queue<int> q1;
    q1.push(3);
    q1.push(2);
    q1.push(1);
    q1.push(4);
    queue<int> q2;
    q2.push(3);
    q2.push(2);
    queue<int> q3;
    q3.push(1);
    q3.push(3);
    q3.push(2);
    q3.push(2);

    cout << levelIsPrefix(tree, q1) << endl;
    cout << levelIsPrefix(tree, q2) << endl;
    cout << levelIsPrefix(tree, q3) << endl;

    return 0;
}