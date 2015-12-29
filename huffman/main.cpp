#include <iostream>
#include "Huffman.h"

using std::cout;
using std::endl;

void printHuffmanTable(map<char, int> table) {
    map<char, int>::iterator tableIterator = table.begin();
    for (; tableIterator != table.end(); tableIterator++) {
        cout << tableIterator->first << " " << tableIterator->second << endl;
    }
}

int main() {
    auto table = Huffman::buildTable("sdaazxcvzxczxz");
    printHuffmanTable(table);
    Tree tree = Huffman::buildTree(table);
    cout << tree << endl;

    return 0;
}