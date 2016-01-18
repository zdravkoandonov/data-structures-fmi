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

class Huffman {
public:
    static map<char, int> buildOccurrenceTable(string);
    static Tree& buildTree(map< char, int>&);
    static map<char, string> buildCodeTable(Tree&);
    static map<char, vector<bool> > buildCodeTableBinary(Tree&);
    static string encode(string, const map<char, string>&);
    static vector<bool> encodeToBinary(string, const map<char, vector<bool> >&);
    static void encodeToFile(string, string, string);
    static vector<int> groupEncoded8bit(string);
    static string decode(string, const Tree&);
    static string decodeFromFile(string, string);
    static double compressionRatio(string, string);
    static void compress(string, string);
    static void decompress(string, string);
};


#endif //HUFFMAN_HUFFMAN_H
