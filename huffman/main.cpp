#include <iostream>
#include "Huffman.h"

using std::cin;
using std::cout;
using std::endl;

template <typename K, typename V>
using MapIterator = typename map<K,V>::iterator;

template <typename K, typename V>
void printMap(map<K, V> table) {
    MapIterator<K, V> tableIterator = table.begin();
    for (; tableIterator != table.end(); tableIterator++) {
        cout << tableIterator->first << " " << tableIterator->second << endl;
    }
}

int main() {
    string input;
    cin >> input;

    map<char, int> table = Huffman::buildOccurrenceTable(input);
    printMap(table);
    Tree &tree = Huffman::buildTree(table);
    cout << tree << endl;
    map<char, string> codeTable = Huffman::buildCodeTable(tree);
    printMap(codeTable);

    cout << Huffman::encode(input, codeTable) << endl;

    return 0;
}