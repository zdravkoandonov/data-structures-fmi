//
// Created by zdravkoandonov on 25.12.15.
//

#include <queue>
#include <sstream>
#include <fstream>
#include "HuffmanTree.h"

using std::priority_queue;
using std::stringstream;
using std::stoi;
using std::ofstream;
using std::ifstream;

HuffmanTree::HuffmanTree(string s) {
    occurrenceTable = buildOccurrenceTable(s);
    tree = buildTree();
    codeTable = buildCodeTable();
}

map<char, int> HuffmanTree::buildOccurrenceTable(string input) {
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

Tree* HuffmanTree::buildTree() {
    priority_queue<Tree*, vector<Tree*>, TreeComparison> trees;
    auto tableIterator = occurrenceTable.begin();
    for (; tableIterator != occurrenceTable.end(); tableIterator++) {
        trees.push(new Tree(tableIterator->second, tableIterator->first));
    }
    while (trees.size() > 1) {
        Tree *tree1 = trees.top();
        trees.pop();
        Tree *tree2 = trees.top();
        trees.pop();

        trees.push(new Tree(*tree1, *tree2));
    }

    return trees.top();
}

void HuffmanTree::dfsCodeTable(Tree *tree, int depth, string currentCode, map<char, string> &codeTable) {
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

map<char, string> HuffmanTree::buildCodeTable() {
    map<char, string> codeTable;
    dfsCodeTable(tree, 0, "", codeTable);

    return  codeTable;
}

string HuffmanTree::encode(string input) {
    unsigned long inputSize = input.size();
    stringstream encodedString;
    for (int i = 0; i < inputSize; i++) {
        encodedString << codeTable.at(input[i]);
    }

    return encodedString.str();
}

void HuffmanTree::encodeToFile(string input, string compressedFileName, string treeFileName) {
    ofstream compressedFile(compressedFileName);
    compressedFile << encode(input);
    compressedFile.close();

    ofstream treeFile(treeFileName);
    treeFile << *tree;
}

string HuffmanTree::decode(string input) {
    unsigned long inputSize = input.size();
    stringstream decodedString;
    const Tree *currentNode = tree;

    for (int i = 0; i < inputSize; i++) {
        if (input[i] == '0')
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;

        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            decodedString << currentNode->symbol;
            currentNode = tree;
        }
    }

    return decodedString.str();
}

string HuffmanTree::decodeFromFile(string compressedFileName, string treeFileName) {
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

        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            decodedString << currentNode->symbol;
            currentNode = tree;
        }
    }

    return decodedString.str();
}

vector<int> HuffmanTree::groupEncoded8bit(string encoded) {
    unsigned long inputSize = encoded.size();
    vector<int> numbers;
    for (unsigned long i = 0; i < inputSize; i += 8) {
        numbers.push_back(stoi(encoded.substr(i, 8), nullptr, 2));
    }

    return numbers;
}

double HuffmanTree::compressionRatio(string rawInput, string encoded) {
    return encoded.size() / (rawInput.size() * 8.0);
}

ostream &operator<<(ostream &outputStream, const HuffmanTree &huffmanTree) {
    outputStream << *(huffmanTree.tree);

    return outputStream;
}

istream &operator>>(istream &inputStream, HuffmanTree &huffmanTree) {
    inputStream >> huffmanTree.tree;

    return inputStream;
}