#include <iostream>
#include <vector>
using namespace std;

string readText(
    const string& INPUT_TYPE
) {
    cout << "Enter " << INPUT_TYPE << ":" << endl;
    string text;
    getline(
        cin,
        text
    );
    return text;
}

vector<string> readNewClientByLine(
    const string& CLIENT_INFORMATION_LINE,
    const string& SEPARATOR = "\\\\"
) {
    vector<string> tokens;
    size_t previous = 0,
           position;
    while (
        (
            position = CLIENT_INFORMATION_LINE.find(
                SEPARATOR,
                previous
            )
        ) != string::npos
    ) {
        tokens.push_back(
            CLIENT_INFORMATION_LINE.substr(
                previous,
                position - previous
            )
        );
        previous = position + SEPARATOR.length();
    }
    tokens.push_back(
        CLIENT_INFORMATION_LINE.substr(
            previous
        )
    );
    return tokens;
}

void printClientAccountInformationRecord(
    const vector<string>& CLIENT_ACCOUNT_INFORMATION_FIELDS
) {
    cout << "Identifier Number: " << CLIENT_ACCOUNT_INFORMATION_FIELDS[0] << endl
        << "PIN Code: " << CLIENT_ACCOUNT_INFORMATION_FIELDS[1] << endl
        << "Full Name: " << CLIENT_ACCOUNT_INFORMATION_FIELDS[2] << ' ' << CLIENT_ACCOUNT_INFORMATION_FIELDS[3] << endl
        << "Mobile Number: " << CLIENT_ACCOUNT_INFORMATION_FIELDS[4] << CLIENT_ACCOUNT_INFORMATION_FIELDS[5] << endl
        << "Balance: " << CLIENT_ACCOUNT_INFORMATION_FIELDS[6] << " Pound";
}

int main() {
    printClientAccountInformationRecord(
        readNewClientByLine(
            readText(
                "Client Account Information Line"
            )
        )
    );
}