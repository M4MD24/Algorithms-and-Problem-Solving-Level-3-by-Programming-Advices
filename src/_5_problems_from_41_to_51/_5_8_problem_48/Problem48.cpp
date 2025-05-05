#include <fstream>
#include <iomanip>
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

vector<string> readClientAccountByLine(
    const string& CLIENT_ACCOUNT_LINE,
    const string& SEPARATOR = "\\\\"
) {
    vector<string> tokens;
    size_t previous = 0,
           position;
    while (
        (
            position = CLIENT_ACCOUNT_LINE.find(
                SEPARATOR,
                previous
            )
        ) != string::npos
    ) {
        tokens.push_back(
            CLIENT_ACCOUNT_LINE.substr(
                previous,
                position - previous
            )
        );
        previous = position + SEPARATOR.length();
    }
    tokens.push_back(
        CLIENT_ACCOUNT_LINE.substr(
            previous
        )
    );
    return tokens;
}

vector<string> readClientsByFile(
    const string& FILE_PATH
) {
    fstream file(
        FILE_PATH,
        ios::in
    );
    vector<string> lines;

    if (file.is_open()) {
        string line;
        while (
            getline(
                file,
                line
            )
        )
            lines.push_back(
                line
            );
        file.close();
    }

    return lines;
}

void printHeader(
    const string& LINE
) {
    cout << LINE << endl;
    cout << "| " << setw(
        20
    ) << "Identifier Number";
    cout << " | " << setw(
        8
    ) << "PIN Code";
    cout << " | " << setw(
        30
    ) << "Full Name";
    cout << " | " << setw(
        25
    ) << "Mobile Number";
    cout << " | " << setw(
        20
    ) << "Balance" << " |";
    cout << endl << LINE << endl;
}

void printBody(
    const vector<string>& CLIENT_ACCOUNTS_INFORMATION_LINES,
    const string& LINE
) {
    for (const string& CLIENT_ACCOUNT_INFORMATION_LINES : CLIENT_ACCOUNTS_INFORMATION_LINES) {
        const vector<string> CLIENT_ACCOUNT_INFORMATION_FIELDS = readClientAccountByLine(
            CLIENT_ACCOUNT_INFORMATION_LINES
        );
        cout << "| " << setw(
            20
        ) << CLIENT_ACCOUNT_INFORMATION_FIELDS[0];
        cout << " | " << setw(
            8
        ) << CLIENT_ACCOUNT_INFORMATION_FIELDS[1];
        cout << " | " << setw(
            30
        ) << CLIENT_ACCOUNT_INFORMATION_FIELDS[2] + " " + CLIENT_ACCOUNT_INFORMATION_FIELDS[3];
        cout << " | " << setw(
            25
        ) << CLIENT_ACCOUNT_INFORMATION_FIELDS[4] + CLIENT_ACCOUNT_INFORMATION_FIELDS[5];
        cout << " | " << setw(
            20
        ) << CLIENT_ACCOUNT_INFORMATION_FIELDS[6] << " |";
        cout << endl << LINE << endl;
    }
}

void printClientAccountsInformationRecordTable(
    const vector<string>& CLIENT_ACCOUNTS_INFORMATION_FIELDS
) {
    const string LINE = "-----------------------------------------------------------------------------------------------------------------------";
    cout << "Client List (" << CLIENT_ACCOUNTS_INFORMATION_FIELDS.size() << " Client(s))" << endl;
    printHeader(
        LINE
    );
    printBody(
        CLIENT_ACCOUNTS_INFORMATION_FIELDS,
        LINE
    );
}

int main() {
    printClientAccountsInformationRecordTable(
        readClientsByFile(
            "src/_5_problems_from_41_to_51/_5_8_problem_48/ClientAccounts.txt"
        )
    );
}