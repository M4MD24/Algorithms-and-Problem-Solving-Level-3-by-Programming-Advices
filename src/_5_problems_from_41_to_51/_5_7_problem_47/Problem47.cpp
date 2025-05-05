#include <fstream>
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
    string& PIN_Code
) {
    do {
        PIN_Code = readText(
            "PIN Code"
        );
    } while (PIN_Code.length() != 4);
}

void readFirstName(
    string& firstName
) {
    firstName = readText(
        "First Name"
    );
}

void readSecondName(
    string& secondName
) {
    secondName = readText(
        "Second Name"
    );
}

void readFullName(
    FullName& fullName
) {
    readFirstName(
        fullName.firstName
    );
    readSecondName(
        fullName.secondName
    );
}

void readCountryCode(
    string& countryCode
) {
    countryCode = readText(
        "Country Code"
    );
}

void readContactNumber(
    string& contactNumber
) {
    contactNumber = readText(
        "Contact Number"
    );
}

void readMobileNumber(
    MobileNumber& mobileNumber
) {
    readCountryCode(
        mobileNumber.countryCode
    );
    readContactNumber(
        mobileNumber.contactNumber
    );
}

void readIdentifierNumber(
    string& identifierNumber
) {
    identifierNumber = readText(
        "Identifier Number"
    );
}

void readBalance(
    long double& balance
) {
    cout << "Enter Balance" << endl;
    cin >> balance;
}

void readNewClient(
    ClientAccount& clientAccount
) {
    readIdentifierNumber(
        clientAccount.identifierNumber
    );
    readPIN_Code(
        clientAccount.PIN_Code
    );
    readFullName(
        clientAccount.fullName
    );
    readMobileNumber(
        clientAccount.mobileNumber
    );
    readBalance(
        clientAccount.balance
    );
}

string clientAccountInformationAsLine(
    const ClientAccount& CLIENT_ACCOUNT,
    const string& SEPARATOR = "\\\\"
) {
    return CLIENT_ACCOUNT.identifierNumber + SEPARATOR +
        CLIENT_ACCOUNT.PIN_Code + SEPARATOR +
        CLIENT_ACCOUNT.fullName.firstName + SEPARATOR +
        CLIENT_ACCOUNT.fullName.secondName + SEPARATOR +
        CLIENT_ACCOUNT.mobileNumber.countryCode + SEPARATOR +
        CLIENT_ACCOUNT.mobileNumber.contactNumber + SEPARATOR +
        to_string(
            CLIENT_ACCOUNT.balance
        );
}

bool readMore() {
    string readMore;
    const string ACCEPT_TEXT = "yes",
                 REJECT_TEXT = "no";
    do {
        cout << "Read More? (" << ACCEPT_TEXT << '/' << REJECT_TEXT << ")" << endl;
        cin >> readMore;
    } while (
        readMore != ACCEPT_TEXT &&
        readMore != REJECT_TEXT
    );
    return readMore == ACCEPT_TEXT;
}

void readNewClients(
    vector<ClientAccount>& clientAccounts
) {
    size_t counter = 1;
    do {
        ClientAccount clientAccount;
        cout << "Client Account [" << counter++ << "]" << endl;
        readNewClient(
            clientAccount
        );
        clientAccounts.push_back(
            clientAccount
        );
    } while (readMore());
}

void printClientAccountsInformationAsLine(
    const vector<ClientAccount>& CLIENT_ACCOUNTS,
    fstream& file
) {
    for (const ClientAccount& CLIENT_ACCOUNT : CLIENT_ACCOUNTS)
        file << clientAccountInformationAsLine(
            CLIENT_ACCOUNT
        ) << endl;
}

void saveClientAccountsInformationAsFile(
    const vector<ClientAccount>& CLIENT_ACCOUNTS
) {
    fstream file;
    const string PATH = "src/_5_problems_from_41_to_51/_5_7_problem_47/ClientAccounts.txt";
    file.open(
        PATH,
        ios::out
    );
    if (file.is_open()) {
        printClientAccountsInformationAsLine(
            CLIENT_ACCOUNTS,
            file
        );
        cout << "Client Accounts Added Successfully to The File: " << PATH;
    }
}

int main() {
    vector<ClientAccount> clientAccounts;
    readNewClients(
        clientAccounts
    );
    saveClientAccountsInformationAsFile(
        clientAccounts
    );
}