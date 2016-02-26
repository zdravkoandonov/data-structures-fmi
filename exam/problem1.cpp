#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Block {
    char block[1024];
};

void createNewFile(list<pair<int, int> > &blockSelectors) {
    map<int, vector<Block> > files;

    ifstream descriptionFile("files.txt");
    int id;
    int blockCount;
    string fileName;
    while (descriptionFile >> id >> blockCount >> fileName) {
        ifstream f(fileName, ios::binary);
        Block tempBlock;
        while (f.read((char*)&tempBlock, sizeof(Block))) {
            files[id].push_back(tempBlock);
        }
        f.close();
    }
    descriptionFile.close();

    ofstream output("output.dat", ios::binary);
    for (pair<int, int> &blockSelector : blockSelectors) {
        if (blockSelector.second >= 0 && blockSelector.second < files[blockSelector.first].size())
            output.write((const char*)&files[blockSelector.first][blockSelector.second], sizeof(Block));
    }
}

void createTestFiles() {
    ofstream f("files.txt");
    f << "1 2 file1.dat" << endl;
    f << "2 3 file2.dat" << endl;
    f << "3 5 file3.dat" << endl;
    f.close();

    ofstream f1("file1.dat", ios::binary);
    for (int i = 0; i < 7; i++) {
        Block b;
        for (int j = 0; j < 1024; j++) {
            b.block[j] = 'a' + i;
        }
        f1.write((const char*)&b, sizeof(Block));
    }
    f1.close();
    ofstream f2("file2.dat", ios::binary);
    for (int i = 0; i < 3; i++) {
        Block b;
        for (int j = 0; j < 1024; j++) {
            b.block[j] = 'A' + i;
        }
        f2.write((const char*)&b, sizeof(Block));
    }
    f2.close();
    ofstream f3("file3.dat", ios::binary);
    for (int i = 0; i < 5; i++) {
        Block b;
        for (int j = 0; j < 1024; j++) {
            b.block[j] = 'J' + i;
        }
        f3.write((const char*)&b, sizeof(Block));
    }
    f3.close();
}

void printBlockFile(string fileName) {
    ifstream f(fileName);
    Block b;
    while (f.read((char*)&b, sizeof(Block)))
        cout << b.block << endl;
    f.close();
}

int main() {
    createTestFiles();

    list<pair<int, int> > selectors = {
            make_pair(1, 3),
            make_pair(2, 2),
            make_pair(3, 3),
            make_pair(1, 0),
            make_pair(1, 7),
            make_pair(1, -3),
            make_pair(2, 0)
    };

    createNewFile(selectors);

    printBlockFile("output.dat");

    return 0;
}