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

size_t capitalLetterCount(
    const string& TEXT
) {
    size_t counter = 0;
    for (const char& CHARACTER : TEXT)
        if (
            isupper(
                CHARACTER
            )
        )
            counter++;
    return counter;
}

size_t smallLetterCount(
    const string& TEXT
) {
    size_t counter = 0;
    for (const char& CHARACTER : TEXT)
        if (
            islower(
                CHARACTER
            )
        )
            counter++;
    return counter;
}

int main() {
    const string TEXT = readText();
    cout << "Text Stats:" << endl;
    cout << "Length = " << TEXT.length();
    cout << "\nCapital Letters = " << capitalLetterCount(
        TEXT
    );
    cout << "\nSmall Letters = " << smallLetterCount(
        TEXT
    );
}