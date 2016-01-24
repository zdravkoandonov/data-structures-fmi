//
// Created by zdravkoandonov on 25.12.15.
//

#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H

#include <map>
#include <string>
#include <queue>
#include "Tree.h"

using std::map;
using std::pair;
using std::string;
using std::priority_queue;
using std::vector;

class HuffmanTree {
    Tree *tree;
    map<char, int> occurrenceTable;
    map<char, string> codeTable;

    map<char, int> buildOccurrenceTable(string);
    Tree *buildTree();
    void dfsCodeTable(Tree*, int, string, map<char, string>&);
    map<char, string> buildCodeTable();
public:
    HuffmanTree(string);
    string encode(string);
    void encodeToFile(string, string, string);
    vector<int> groupEncoded8bit(string);
    string decode(string);
    string decodeFromFile(string, string);
    double compressionRatio(string, string);

    friend ostream& operator<<(ostream&, const HuffmanTree&);
    friend istream& operator>>(istream&, HuffmanTree&);
};


#endif //HUFFMAN_HUFFMAN_H
