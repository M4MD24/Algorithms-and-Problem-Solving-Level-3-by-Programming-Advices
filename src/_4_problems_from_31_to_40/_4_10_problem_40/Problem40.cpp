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

string joinText(
    const string WORDS[3],
    const size_t LENGTH,
    const string& DELIMITER
) {
    string text;
    for (int index = 0; index < LENGTH; ++index)
        text += WORDS[index] + DELIMITER;
    if (!WORDS->empty())
        text.erase(
            text.size() - DELIMITER.size()
        );
    return text;
}

int main() {
    const vector<string> WORDS_1 = {
        "Android",
        "Applications",
        "Developer"
    };
    const int WORD_COUNT = 3;
    const string WORDS_2[WORD_COUNT] = {
        "Android",
        "Applications",
        "Developer"
    };

    cout << "Join Text with Vector:" << endl << joinText(
        WORDS_1,
        " "
    ) << endl;

    cout << "Join Text with Array:" << endl << joinText(
        WORDS_2,
        WORD_COUNT,
        " "
    );
}