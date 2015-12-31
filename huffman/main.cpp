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

template <typename T>
void printVector(vector<T> v) {
    int size = v.size();
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    string input = "abracadabra";
    //cin >> input;

    map<char, int> table = Huffman::buildOccurrenceTable(input);
    printMap(table);
    Tree &tree = Huffman::buildTree(table);
    cout << tree << endl;
    map<char, string> codeTable = Huffman::buildCodeTable(tree);
    printMap(codeTable);

    string encoded = Huffman::encode(input, codeTable);
    cout << encoded << endl;

    cout << Huffman::decode(encoded, tree) << endl;

    printVector(Huffman::groupEncoded8bit(encoded));

    cout << Huffman::compressionRatio(input, encoded) << endl;

    return 0;
}