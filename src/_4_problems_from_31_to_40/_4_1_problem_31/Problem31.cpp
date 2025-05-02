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

char readLetter() {
    char character;
    do {
        cout << "Enter Letter:" << endl;
        cin >> character;
    } while (
        !isalpha(
            character
        )
    );
    return character;
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

char lowercaseLetter(
    const char& CHARACTER
) { return static_cast<char>(CHARACTER | 32); }

unsigned long long targetLetterCount(
    const string& TEXT,
    const char& TARGET_CHARACTER,
    const bool& MATCH_CASE = true
) {
    unsigned long long counter = 0;
    if (MATCH_CASE)
        for (const char& CHARACTER : TEXT)
            counter += CHARACTER == TARGET_CHARACTER;
    else
        for (const char& CHARACTER : TEXT)
            counter += lowercaseLetter(
                    CHARACTER
                ) == lowercaseLetter(
                    TARGET_CHARACTER
                ) &&
                isalpha(
                    CHARACTER
                );
    return counter;
}

int main() {
    const string TEXT = readText();
    const char TARGET_CHARACTER = readLetter();

    cout << "Letter " << TARGET_CHARACTER << " Count = " << targetLetterCount(
        TEXT,
        TARGET_CHARACTER
    );

    cout << "\nLetter " << TARGET_CHARACTER << " or " << invertLetterCase(
        TARGET_CHARACTER
    ) << " Count = " << targetLetterCount(
        TEXT,
        TARGET_CHARACTER,
        false
    );
}