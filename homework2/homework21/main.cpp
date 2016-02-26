/// use c++11

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Data {
    typedef enum { integer, real, dog } Type;
    Type type;
    int number;
    double realNumber;
    char *dogName;
public:
    Data() {}
    Data(int number) : number(number), type(integer) {}
    Data(double realNumber) : realNumber(realNumber), type(real) {}
    Data(char *dogName) : dogName(dogName), type(dog) {}
    operator int() {
        return number;
    }
    operator double() {
        return realNumber;
    }
    operator char*() {
        return dogName;
    }
    void print(ostream &stream = cout) {
        stream << type << " ";
        switch(type) {
            case integer:
                stream << number << " ";
                break;
            case real:
                stream << realNumber << " ";
                break;
            case dog:
                stream << dogName << " ";
                break;
        }
    }
    Data &scan(istream &stream) {
        int type;
        stream >> type;
        switch (type) {
            case 0:
                this->type = integer;
                stream >> number;
                break;
            case 1:
                this->type = real;
                stream >> realNumber;
                break;
            case 2:
                this->type = dog;
                dogName = new char[100];
                stream >> dogName;
                break;
        }
        return *this;
    }
};

class Tree {
    Data data;
    Tree *descendants[4];
public:
    Tree(Data data) : data(data) {
        for (int i = 0; i < 4; ++i) {
            descendants[i] = NULL;
        }
    }
    void addDescendant(Tree *tree, int position) {
        if (position <= 3 && position >= 0) {
            descendants[position] = tree;
        }
    }
    Tree *&getDescendant(int position) {
        if (position <= 3 && position >= 0) {
            return descendants[position];
        }
    }
    Data getData() {
        return data;
    }

    friend istream &operator>>(istream &stream, Tree *&tree);
    friend ostream &operator<<(ostream &stream, Tree *tree);
};

istream &operator>>(istream &stream, Tree *&tree) {
    if (stream.peek() >= '0' && stream.peek() <= '3') {
        tree = new Tree(Data().scan(stream));
        stream.ignore();
        for (int i = 0; i < 4; ++i) {
            stream >> tree->getDescendant(i);
        }
    }
    else if (stream.peek() == '#') {
        stream.ignore(2);
    }

    return stream;
}

ostream &operator<<(ostream &stream, Tree *tree) {
    if (tree == NULL) {
        stream << "# ";
    }
    else {
        tree->getData().print(stream);
        for (int i = 0; i < 4; ++i) {
            stream << tree->getDescendant(i);
        }
    }

    return stream;
}

int main() {
    // populate file "tree"
    ofstream treeNameFileGen("tree");
    treeNameFileGen << "treefile";
    treeNameFileGen.close();

    // find out the name of the file
    ifstream treeNameFile("tree");
    string fileName;
    treeNameFile >> fileName;
    treeNameFile.close();

    // serialize
    ofstream ofs(fileName);

    Tree tree1("Brick"), tree2(13), tree3(1.235), tree4("Flash");
    tree1.addDescendant(&tree2, 0);
    tree1.addDescendant(&tree3, 2);
    tree1.addDescendant(&tree4, 3);

    ofs << &tree1;
    ofs.close();

    // deserialize
    ifstream ifs(fileName);
    Tree *tree;
    ifs >> tree;
    ifs.close();

    // serialize to cout - should match the derialization from the file
    cout << tree << endl;

    return 0;
}
