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

size_t wordCount(
    const string& TEXT
) {
    size_t index = 0,
           counter = 0;
    while (TEXT[index]) {
        if (
            TEXT[index] != ' ' &&
            TEXT[index] != '\t' &&
            TEXT[index] != '\n' &&
            (
                index == 0 ||
                TEXT[index - 1] == ' ' ||
                TEXT[index - 1] == '\t' ||
                TEXT[index - 1] == '\n'
            )
        )
            counter++;
        index++;
    }
    return counter;
}

int main() {
    const string TEXT = readText();
    cout << "Word Count: " << wordCount(
        TEXT
    );
}