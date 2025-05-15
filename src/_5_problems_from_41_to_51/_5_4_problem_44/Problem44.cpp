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

void removeAllPunctuations(
    string& text
) {
    string textAfterRemoveAllPunctuations;
    for (const char& CHARACTER : text)
        if (
            !ispunct(
                CHARACTER
            )
        )
            textAfterRemoveAllPunctuations += CHARACTER;
    text = textAfterRemoveAllPunctuations;
}

int main() {
    string text = readText();

    cout << "Original Text:" << endl
        << text << endl << endl;

    removeAllPunctuations(
        text
    );

    cout << "After Removing Punctuations in Text:" << endl
        << text;
}