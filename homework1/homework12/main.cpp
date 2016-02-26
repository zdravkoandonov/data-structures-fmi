#include <iostream>
#include <list>
#include <string>

using namespace std;

void advanceLoopThroughNames(list<string> &names, list<string>::iterator &it, int k) {
    for (int i = 0; i < k; ++i) {
        if (it == names.end()) {
            it = names.begin();
        }
        ++it;
    }
}

int main() {
    int n = 5, k = 3;
    string tempName;
    list<string> names;

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> tempName;
        names.push_back(tempName);
    }

    list<string>::iterator personToRemoveIterator = names.begin();
    while (names.size() > 1) {
        cout << *personToRemoveIterator << endl;
        names.erase(personToRemoveIterator++);
        advanceLoopThroughNames(names, personToRemoveIterator, k-1);
    }
    cout << names.front() << endl;

    return 0;
}