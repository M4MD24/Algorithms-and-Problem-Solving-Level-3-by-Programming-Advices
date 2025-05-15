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
    const size_t TEXT_TO_REPLACE_LENGTH = TEXT_TO_REPLACE.length(),
                 REPLACE_TEXT_LENGTH = REPLACE_TEXT.length();

    while (
        (
            position = text.find(
                TEXT_TO_REPLACE,
                position
            )
        ) != string::npos
    ) {
        const string BEGIN_TEXT = text.substr(
            0,
            position
        );
        const string END_TEXT = text.substr(
            position + TEXT_TO_REPLACE_LENGTH
        );

        text = BEGIN_TEXT + REPLACE_TEXT += END_TEXT;

        position += REPLACE_TEXT_LENGTH;
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
        << text << endl;

    replaceText(
        text,
        TEXT_TO_REPLACE,
        REPLACE_TEXT
    );

    cout << "After Replacing The Text: " << endl
        << text;
}