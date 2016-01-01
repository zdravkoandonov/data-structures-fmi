#include <iostream>
#include <fstream>
#include "Huffman.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

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
    unsigned long size = v.size();
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    string input = "abracadabra1231231121";
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

    Huffman::encodeToFile(input, "comp", "tree");
    cout << "FROMFILE:: " << Huffman::decodeFromFile("comp", "tree") << " ::FROMFILE\n";

    // Test serialization/deserialization of a huffman tree
    ofstream outFile("export");
    outFile << tree;
    outFile.close();

    Tree *testTree;
    ifstream inFile("export");
    inFile >> testTree;
    inFile.close();

    cout << *testTree;

    cout << "\nEND\n" << endl;

    return 0;
}