//
// Created by zdravkoandonov on 25.12.15.
//

#include <queue>
#include <sstream>
#include <fstream>
#include "Huffman.h"

using std::priority_queue;
using std::stringstream;
using std::stoi;
using std::ifstream;
using std::ofstream;

map<char, int> Huffman::buildOccurrenceTable(string input) {
    map<char, int> table;
    map<char, int>::iterator tableIterator;
    unsigned long inputSize = input.size();

    for (int i = 0; i < inputSize; i++) {
        if ((tableIterator = table.find(input[i])) != table.end())
            (*tableIterator).second++;
        else
            table.insert(pair<char, int>(input[i], 1));
    }

    return table;
}

Tree& Huffman::buildTree(map<char, int> &table) {
    priority_queue<Tree*, vector<Tree*>, TreeComparison> trees;
    auto tableIterator = table.begin();
    for (; tableIterator != table.end(); tableIterator++) {
        trees.push(new Tree(tableIterator->second, tableIterator->first));
    }
    while (trees.size() > 1) {
        Tree *tree1 = trees.top();
        trees.pop();
        Tree *tree2 = trees.top();
        trees.pop();

        trees.push(new Tree(*tree1, *tree2));
    }

    return *trees.top();
}

void dfsCodeTable(Tree *tree, int depth, string currentCode, map<char, string> &codeTable) {
    if (tree) {
        if (tree->left && tree->right) {
            dfsCodeTable(tree->left, depth + 1, currentCode + '0', codeTable);
            dfsCodeTable(tree->right, depth + 1, currentCode + '1', codeTable);
        }
        else {
            codeTable.insert(pair<char, string>(tree->symbol, currentCode));
        }
    }
}

map<char, string> Huffman::buildCodeTable(Tree &tree) {
    map<char, string> codeTable;
    dfsCodeTable(&tree, 0, "", codeTable);

    return  codeTable;
}

string Huffman::encode(string input, const map<char, string> &codeTable) {
    unsigned long inputSize = input.size();
    stringstream encodedString;
    for (int i = 0; i < inputSize; i++) {
        encodedString << codeTable.at(input[i]);
    }

    return encodedString.str();
}

void Huffman::encodeToFile(string input, string compressedFileName, string treeFileName) {
    map<char, int> table = Huffman::buildOccurrenceTable(input);
    Tree &tree = Huffman::buildTree(table);
    map<char, string> codeTable = Huffman::buildCodeTable(tree);

    ofstream compressedFile(compressedFileName);
    compressedFile << encode(input, codeTable);
    compressedFile.close();

    ofstream treeFile(treeFileName);
    treeFile << tree;
}

string Huffman::decode(string input, const Tree &tree) {
    unsigned long inputSize = input.size();
    stringstream decodedString;
    const Tree *currentNode = &tree;

    for (int i = 0; i < inputSize; i++) {
        if (input[i] == '0')
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;

        if (currentNode->left == NULL && currentNode->right == NULL) {
            decodedString << currentNode->symbol;
            currentNode = &tree;
        }
    }

    return decodedString.str();
}

string Huffman::decodeFromFile(string compressedFileName, string treeFileName) {
    Tree *tree;
    ifstream treeFile(treeFileName);
    treeFile >> tree;
    treeFile.close();

    ifstream compressedFile(compressedFileName);
    stringstream decodedString;
    const Tree *currentNode = tree;

    while (!compressedFile.eof()) {
        if (compressedFile.get() == '0')
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;

        if (currentNode->left == NULL && currentNode->right == NULL) {
            decodedString << currentNode->symbol;
            currentNode = tree;
        }
    }

    return decodedString.str();
}

vector<int> Huffman::groupEncoded8bit(string input) {
    unsigned long inputSize = input.size();
    vector<int> numbers;
    for (unsigned long i = 0; i < inputSize; i += 8) {
        numbers.push_back(stoi(input.substr(i, 8), NULL, 2));
    }

    return numbers;
}

double Huffman::compressionRatio(string rawInput, string encoded) {
    return encoded.size() / (rawInput.size() * 8.0);
}
