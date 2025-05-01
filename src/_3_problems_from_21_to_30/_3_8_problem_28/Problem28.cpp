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

char invertLetterCase(
    const char& CHARACTER
) {
    return static_cast<char>(
        isupper(
            CHARACTER
        )
            ? tolower(
                CHARACTER
            )
            : toupper(
                CHARACTER
            )
    );
}

string invertAllLetterCases(
    string text
) {
    for (char& character : text)
        character = invertLetterCase(
            character
        );
    return text;
}

int main() {
    const string TEXT = readText();
    cout << "Original Text:\n" << TEXT;
    cout << "\n\nInverted Letter Cases of Text:\n" << invertAllLetterCases(
        TEXT
    );
}