#include <iostream>
using namespace std;

string readText(
    const string& INPUT_MESSAGE
) {
    cout << INPUT_MESSAGE << endl;
    string text;
    getline(
        cin,
        text
    );
    return text;
}

void replaceText(
    string& text,
    const string& TEXT_TO_REPLACE,
    const string& REPLACE_TEXT
) {
    size_t position = 0;
    while (
        (
            position = text.find(
                TEXT_TO_REPLACE,
                position
            )
        ) != string::npos
    ) {
        text.replace(
            position,
            TEXT_TO_REPLACE.length(),
            REPLACE_TEXT
        );
        position += REPLACE_TEXT.length();
    }
}

int main() {
    string text = readText(
        "Enter Text:"
    );
    const string TEXT_TO_REPLACE = readText(
                     "Enter Text to Replace:"
                 ),
                 REPLACE_TEXT = readText(
                     "Enter Replaced text:"
                 );

    cout << "Original Text:" << endl
        << text  << endl;

    replaceText(
        text,
        TEXT_TO_REPLACE,
        REPLACE_TEXT
    );

    cout << "Reversed Text:" << endl
        << text;
}