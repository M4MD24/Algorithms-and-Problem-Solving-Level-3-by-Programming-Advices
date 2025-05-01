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

bool isVowel(
    const char CHARACTER
) {
    static const string VOWELS = "aeiouAEIOU";
    return VOWELS.find(
        CHARACTER
    ) != string::npos;
}

void printVowelsInText(
    const string& TEXT
) {
    for (const char& CHARACTER : TEXT)
        if (
            isVowel(
                CHARACTER
            )
        )
            cout << CHARACTER << '\t';

}

int main() {
    const string TEXT = readText();
    cout << "Vowels in Text:" << endl;
    printVowelsInText(TEXT);
}