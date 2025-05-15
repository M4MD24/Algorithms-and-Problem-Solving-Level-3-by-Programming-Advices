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
    vector<string> &words,
    const string &DELIMITER
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

string reverseWordOrder(
    string text
) {
    vector<string> reversedText;
    const string &DELIMITER = " ";
    splitText(
        text,
        reversedText,
        DELIMITER
    );
    vector<string>::iterator iterator = reversedText.end();
    text.clear();
    while (iterator-- != reversedText.begin())
        text += *iterator + DELIMITER;
    if (!text.empty())
        text.erase(
            text.size() - DELIMITER.size()
        );
    return text;
}

int main() {
    const string TEXT = readText();
    cout << "Original Text:" << endl
        << TEXT << endl;

    cout << "Reversed Word Order: " << endl
        << reverseWordOrder(
            TEXT
        );
}