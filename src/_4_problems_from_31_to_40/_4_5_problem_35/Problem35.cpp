#include <iostream>
using namespace std;

string readText() {
    cout << "Enter Text:" << endl;
    string text;
    getline(
        cin,
        text
    );
    return text;
}

void printWords(
    const string& TEXT
) {
    cout << "Words:" << endl;
    size_t startPosition = 0,
           endPosition;
    while (
        (
            endPosition = TEXT.find(
                ' ',
                startPosition
            )
        ) != string::npos
    ) {
        cout << TEXT.substr(
            startPosition,
            endPosition - startPosition
        ) << endl;
        startPosition = endPosition + 1;
    }
    if (startPosition < TEXT.length())
        cout << TEXT.substr(
            startPosition
        ) << endl;
}

int main() {
    printWords(
        readText()
    );
}