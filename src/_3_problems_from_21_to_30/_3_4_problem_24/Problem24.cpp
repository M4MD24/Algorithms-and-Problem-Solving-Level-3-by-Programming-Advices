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

void printFirstUppercaseLetters(
    const string& TEXT
) {
    cout << "First Uppercase Letters:" << endl;
    if (
        const unsigned long long TEXT_LENGTH = TEXT.size();
        TEXT_LENGTH > 0
    ) {
        if (
            isupper(
                TEXT[0]
            )
        )
            cout << TEXT[0] << endl;
        for (
            unsigned long long firstLetterIndex = 0, secondLetterIndex = 1;
            secondLetterIndex < TEXT_LENGTH;
            ++firstLetterIndex, ++secondLetterIndex
        ) {
            const char FIRST_CHARACTER = TEXT[firstLetterIndex],
                       SECOND_CHARACTER = TEXT[secondLetterIndex];
            if (
                isspace(
                    FIRST_CHARACTER
                ) && isupper(
                    SECOND_CHARACTER
                )
            )
                cout << SECOND_CHARACTER << endl;
        }
    }
}

int main() {
    printFirstUppercaseLetters(
        readText()
    );
}