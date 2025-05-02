#include <iostream>
#include "Trim.h"
using namespace std;
using namespace Trim;

string readText() {
    cout << "Enter Text:" << endl;
    string text;
    getline(
        cin,
        text
    );
    return text;
}

int main() {
    const string TEXT = readText();
    cout << "Original Text: " << TEXT << endl;
    cout << "Trim: " << trim(
        TEXT
    ) << endl;
    cout << "Trim Left: " << trimLeft(
        TEXT
    ) << endl;
    cout << "Trim Right: " << trimRight(
        TEXT
    );
}