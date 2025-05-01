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

long long countOfVowels(
    const string& TEXT
) {
    long long counter = 0;
    for (const char& CHARACTER : TEXT)
        counter += isVowel(
            CHARACTER
        );
    return counter;
}

int main() {
    const string TEXT = readText();
    cout << "Count of Vowels is: " << countOfVowels(TEXT);
}