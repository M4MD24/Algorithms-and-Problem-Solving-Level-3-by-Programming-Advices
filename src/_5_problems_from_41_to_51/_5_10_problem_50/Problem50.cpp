#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct MobileNumber {
    string countryCode,
           contactNumber;
};

struct FullName {
    string firstName,
           secondName;
};

struct ClientAccount {
    string identifierNumber;
    string PIN_Code;
    FullName fullName;
    MobileNumber mobileNumber;
    long double balance = 0.0;
};

string readText(
    const string& INPUT_TYPE
) {
    cout << "Enter " << INPUT_TYPE << ":" << endl;
    string text;
    cin >> text;
    return text;
}

void readPIN_Code(
    string& PIN_Code,
    const string& PIN_CODE_FIELD
) { PIN_Code = PIN_CODE_FIELD; }

void readFirstName(
    string& firstName,
    const string& FIRST_NAME_FIELD
) { firstName = FIRST_NAME_FIELD; }

void readSecondName(
    string& secondName,
    const string& SECOND_NAME_FIELD
) { secondName = SECOND_NAME_FIELD; }

void readFullName(
    FullName& fullName,
    const string& FIRST_NAME_FIELD,
    const string& SECOND_NAME_FIELD
) {
    readFirstName(
        fullName.firstName,
        FIRST_NAME_FIELD
    );
    readSecondName(
        fullName.secondName,
        SECOND_NAME_FIELD
    );
}

void readCountryCode(
    string& countryCode,
    const string& COUNTRY_CODE_FIELD
) { countryCode = COUNTRY_CODE_FIELD; }

void readContactNumber(
    string& contactNumber,
    const string& CONTACT_NUMBER_FIELD
) { contactNumber = CONTACT_NUMBER_FIELD; }

void readMobileNumber(
    MobileNumber& mobileNumber,
    const string& COUNTRY_CODE_FIELD,
    const string& CONTACT_NUMBER_FIELD
) {
    readCountryCode(
        mobileNumber.countryCode,
        COUNTRY_CODE_FIELD
    );
    readContactNumber(
        mobileNumber.contactNumber,
        CONTACT_NUMBER_FIELD
    );
}

void readIdentifierNumber(
    string& identifierNumber,
    const string& IDENTIFIER_NUMBER_FIELD
) { identifierNumber = IDENTIFIER_NUMBER_FIELD; }

void readBalance(
    long double& balance,
    const string& BALANCE_FIELD
) {
    balance = stold(
        BALANCE_FIELD
    );
}

void readClientAccountFields(
    ClientAccount& clientAccount,
    const vector<string>& FIELDS
) {
    readIdentifierNumber(
        clientAccount.identifierNumber,
        FIELDS[0]
    );
    readPIN_Code(
        clientAccount.PIN_Code,
        FIELDS[1]
    );
    readFullName(
        clientAccount.fullName,
        FIELDS[2],
        FIELDS[3]
    );
    readMobileNumber(
        clientAccount.mobileNumber,
        FIELDS[4],
        FIELDS[5]
    );
    readBalance(
        clientAccount.balance,
        FIELDS[6]
    );
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
    const ClientAccount& CLIENT_ACCOUNT,
    const string& LINE
) {
    cout << "| " << setw(
        20
    ) << CLIENT_ACCOUNT.identifierNumber;
    cout << " | " << setw(
        8
    ) << CLIENT_ACCOUNT.PIN_Code;
    cout << " | " << setw(
        30
    ) << CLIENT_ACCOUNT.fullName.firstName + " " + CLIENT_ACCOUNT.fullName.secondName;
    cout << " | " << setw(
        25
    ) << CLIENT_ACCOUNT.mobileNumber.countryCode + CLIENT_ACCOUNT.mobileNumber.contactNumber;
    cout << " | " << setw(
        20
    ) << CLIENT_ACCOUNT.balance << " |";
    cout << endl << LINE << endl;
}

void printClientAccountsInformationRecordTable(
    const ClientAccount& CLIENT_ACCOUNT
) {
    const string LINE = "-----------------------------------------------------------------------------------------------------------------------";
    printHeader(
        LINE
    );
    printBody(
        CLIENT_ACCOUNT,
        LINE
    );
}

ClientAccount findIdentifierNumber(
    const vector<ClientAccount>& CLIENT_ACCOUNT_INFORMATION_RECORDS,
    const string& IDENTIFIER_NUMBER_TARGET
) {
    for (const ClientAccount& CLIENT_ACCOUNT : CLIENT_ACCOUNT_INFORMATION_RECORDS)
        if (CLIENT_ACCOUNT.identifierNumber == IDENTIFIER_NUMBER_TARGET) {
            cout << "Is Found!" << endl;
            printClientAccountsInformationRecordTable(
                CLIENT_ACCOUNT
            );
            return CLIENT_ACCOUNT;
        }
    cout << "Isn't Found!";
    return ClientAccount{};
}

void convertLineToClientAccountRecord(
    const string& CLIENT_ACCOUNT_LINE,
    ClientAccount& clientAccount
) {
    readClientAccountFields(
        clientAccount,
        readClientAccountByLine(
            CLIENT_ACCOUNT_LINE
        )
    );
}

vector<ClientAccount> convertLinesToClientAccountsRecord(
    const vector<string>& CLIENT_ACCOUNT_LINES
) {
    vector<ClientAccount> clientAccountInformationRecords;
    for (const string& CLIENT_ACCOUNT_LINE : CLIENT_ACCOUNT_LINES) {
        ClientAccount clientAccount;
        convertLineToClientAccountRecord(
            CLIENT_ACCOUNT_LINE,
            clientAccount
        );
        clientAccountInformationRecords.push_back(
            clientAccount
        );
    }
    return clientAccountInformationRecords;
}

bool deleteNow() {
    string deleteNow;
    const string ACCEPT_TEXT = "yes",
                 REJECT_TEXT = "no";
    do {
        cout << "Do you want delete it? (" << ACCEPT_TEXT << '/' << REJECT_TEXT << ")" << endl;
        cin >> deleteNow;
    } while (
        deleteNow != ACCEPT_TEXT &&
        deleteNow != REJECT_TEXT
    );
    return deleteNow == ACCEPT_TEXT;
}

void deleteClientAccountFromFileByIdentifierNumber(
    const ClientAccount& CLIENT_ACCOUNT,
    const string& PATH
) {
    if (!CLIENT_ACCOUNT.identifierNumber.empty())
        if (deleteNow()) {
            const vector<string> LINES = readClientsByFile(
                PATH
            );
            vector<string> updatedLines;

            for (const string& LINE : LINES) {
                ClientAccount currentClient;
                convertLineToClientAccountRecord(
                    LINE,
                    currentClient
                );
                if (currentClient.identifierNumber != CLIENT_ACCOUNT.identifierNumber)
                    updatedLines.push_back(
                        LINE
                    );
            }

            ofstream file(
                PATH,
                ios::out | ios::trunc
            );
            for (const string& UPDATED_LINE : updatedLines)
                file << UPDATED_LINE << endl;
            file.close();

            cout << "Client account has been deleted successfully." << endl;
        }
}

int main() {
    const string IDENTIFIER_NUMBER_TARGET = readText(
        "Identifier Number"
    );
    const string PATH = "src/_5_problems_from_41_to_51/_5_10_problem_50/ClientAccounts.txt";
    deleteClientAccountFromFileByIdentifierNumber(
        findIdentifierNumber(
            convertLinesToClientAccountsRecord(
                readClientsByFile(
                    PATH
                )
            ),
            IDENTIFIER_NUMBER_TARGET
        ),
        PATH
    );
}