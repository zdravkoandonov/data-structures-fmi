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

class Huffman {
public:
    static map<char, int> buildOccurrenceTable(string);
    static Tree& buildTree(map< char, int>&);
    static map<char, string> buildCodeTable(Tree&);
    static string encode(string, const map<char, string>&);
    static string decode(string, const Tree&);
};


#endif //HUFFMAN_HUFFMAN_H
