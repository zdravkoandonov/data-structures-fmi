/// Use c++11

#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <limits>

using namespace std;

void prepareFile(ofstream &file) {
    file << "<tag1><tag2>asd</tag2><tag3></tag3></tag1>";
}

bool containsBalancedTags(ifstream &file) {
    stack<string> openTags;
    bool isOpening;
    string tag;

    // remove all unrelated text before tags
    file.ignore(numeric_limits<streamsize>::max(), '<');
    while (!file.eof()) {
        char filePeek = file.peek();
        if (file.peek() == '/') {
            file.ignore();
            isOpening = false;
        }
        else {
            isOpening = true;
        }
        getline(file, tag, '>');
        if (isOpening) {
            openTags.push(tag);
        }
        else if (!openTags.empty() && openTags.top() == tag) {
            openTags.pop();
        }
        else {
            return false;
        }
        // remove all unrelated text between tags
        file.ignore(numeric_limits<streamsize>::max(), '<');
    }

    return openTags.size() == 0;
}

int main() {
    const string FILENAME = "validate";

    ofstream fileToPrepare(FILENAME);
    prepareFile(fileToPrepare);
    fileToPrepare.close();

    ifstream file(FILENAME);

    if (file.fail()) {
        cout << "The file failed to open. Are you sure the file '" << FILENAME << "' exists?" << endl;
    }
    else if (containsBalancedTags(file)) {
        cout << "Contains balanced tags!" << endl;
    }
    else {
        cout << "Does not contain balanced tags!" << endl;
    }

    file.close();

    return 0;
}
