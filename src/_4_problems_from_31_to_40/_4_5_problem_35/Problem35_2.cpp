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
    for (const char& CHARACTER : TEXT)
        if (CHARACTER != ' ')
            cout << CHARACTER;
        else
            cout << '\n';
}

int main() {
    printWords(
        readText()
    );
}