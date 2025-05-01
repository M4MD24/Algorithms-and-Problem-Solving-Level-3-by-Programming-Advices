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

void printFirstCharacters(
    const string& TEXT
) {
    cout << "First Characters:" << endl;
    bool isStartOfWord = true;
    for (const char CHARACTER : TEXT) {
        if (
            isStartOfWord &&
            !isspace(
                CHARACTER
            )
        ) {
            cout << CHARACTER << endl;
            isStartOfWord = false;
        }
        if (isspace(
            CHARACTER
        ))
            isStartOfWord = true;
    }
}

int main() {
    printFirstCharacters(
        readText()
    );
}