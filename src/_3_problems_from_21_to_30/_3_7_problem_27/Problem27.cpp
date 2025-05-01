#include <iostream>
using namespace std;

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

int main() {
    const char CHARACTER = readLetter();
    cout << "Original Letter:\n" << CHARACTER;
    cout << "\n\nInverted Letter:\n" << invertLetterCase(
        CHARACTER
    );
}