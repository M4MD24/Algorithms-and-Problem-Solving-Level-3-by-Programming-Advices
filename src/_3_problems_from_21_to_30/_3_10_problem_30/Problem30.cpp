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

char readCharacter() {
    char character;
    cout << "Enter Character:" << endl;
    cin >> character;
    return character;
}

size_t targetLetterCount(
    const string& TEXT,
    const char& TARGET_CHARACTER
) {
    size_t counter = 0;
    for (const char& CHARACTER : TEXT)
        if (CHARACTER == TARGET_CHARACTER)
            counter++;
    return counter;
}

int main() {
    const string TEXT = readText();
    const char TARGET_CHARACTER = readCharacter();
    cout << "Target Letter Count = " << targetLetterCount(
        TEXT,
        TARGET_CHARACTER
    );
}