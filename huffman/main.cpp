#include <iostream>
#include <fstream>
#include <cstring>
#include "HuffmanTree.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

template <typename T>
void printVector(vector<T> v) {
    unsigned long size = v.size();
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        bool compress = true; // compress by default
        string inputFileName, outputFileName;
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-c") == 0) {
                compress = true;
            }
            else if (strcmp(argv[i], "-d") == 0) {
                compress = false;
            }
            else if (strcmp(argv[i], "-i") == 0) {
                inputFileName = argv[++i];
            }
            else if (strcmp(argv[i], "-o") == 0) {
                outputFileName = argv[++i];
            }
        }
        cout << compress << " " << inputFileName << " " << outputFileName << endl;
    }
    else {
        // SOME TESTS

        string input = "abracadabra1231231121";
        //cin >> input;

        HuffmanTree huffmanTree(input);

        string encoded = huffmanTree.encode(input);
        cout << encoded << endl;

        cout << huffmanTree.decode(encoded) << endl;

        printVector(huffmanTree.groupEncoded8bit(encoded));

        cout << huffmanTree.compressionRatio(input, encoded) << endl;

        huffmanTree.encodeToFile(input, "comp", "tree");
        cout << "FROMFILE:: " << huffmanTree.decodeFromFile("comp", "tree") << " ::FROMFILE\n";

        // Test serialization/deserialization of a HuffmanTree tree
        ofstream outFile("export");
        outFile << huffmanTree;
        outFile.close();

        Tree *testTree;
        ifstream inFile("export");
        inFile >> testTree;
        inFile.close();

        cout << *testTree;

        cout << "\nEND\n" << endl;
    }

    return 0;
}