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
    string text
) {
    cout << "Words:" << endl;
    const string SPLITTER_TARGET = " ";
    size_t position;
    while (
        (
            position = text.find(
                SPLITTER_TARGET
            )
        ) != string::npos
    ) {
        cout << text.substr(
            0,
            position
        ) << endl;
        text.erase(
            0,
            position + SPLITTER_TARGET.length()
        );
    }
    cout << text << endl;
}

int main() {
    printWords(
        readText()
    );
}