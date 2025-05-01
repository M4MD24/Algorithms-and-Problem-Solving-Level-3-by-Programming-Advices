#include <iostream>
#include "TextUtils.h"
using namespace TextUtils;

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
    cout << "Original Text:\n" << TEXT;
    cout << "\n\nUppercase Text:\n" << toUppercaseText(
        TEXT
    );
    cout << "\n\nLowercase Text:\n" << toLowercaseText(
        TEXT
    );
}