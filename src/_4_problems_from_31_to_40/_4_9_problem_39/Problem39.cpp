#include <iostream>
#include <vector>
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

void splitText(
    string text,
    vector<string>& words,
    const string& DELIMITER
) {
    size_t position;
    while (
        (
            position = text.find(
                DELIMITER
            )
        ) != string::npos
    ) {
        words.push_back(
            text.substr(
                0,
                position
            )
        );
        text.erase(
            0,
            position + DELIMITER.length()
        );
    }
    words.push_back(
        text
    );
}

void printWords(
    const vector<string>& WORDS
) {
    cout << "Words:" << endl;
    for (const string& WORD : WORDS)
        cout << WORD << endl;
}

string joinText(
    const vector<string>& WORDS,
    const string& DELIMITER
) {
    string text;
    for (const string& WORD : WORDS)
        text += WORD + DELIMITER;
    if (!WORDS.empty())
        text.erase(
            text.size() - DELIMITER.size()
        );
    return text;
}

int main() {
    string text = readText();
    vector<string> words;

    splitText(
        text,
        words,
        " "
    );

    text = joinText(
        words,
        "-"
    );

    cout << text;
}