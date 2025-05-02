#include <iostream>
using namespace std;

char readCharacter() {
    char character;
    cout << "Enter Character:" << endl;
    cin >> character;
    return character;
}

bool isVowel(
    const char CHARACTER
) {
    static const string VOWELS = "aeiouAEIOU";
    return VOWELS.find(
        CHARACTER
    ) != string::npos;
}

int main() {
    const char CHARACTER = readCharacter();
    cout << "Character " << CHARACTER << " is Vowel?" << endl;
    cout << (
        isVowel(
            CHARACTER
        )
            ? "Yes"
            : "No"
    );
}