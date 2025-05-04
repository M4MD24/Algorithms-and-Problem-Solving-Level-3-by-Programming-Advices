#include <iostream>
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
    string pinCode;
    FullName fullName;
    MobileNumber mobileNumber;
    long double balance = 0.0;
};

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

void readPinCode(
    string& pinCode
) {
    do {
        pinCode = readText(
            "PIN Code"
        );
    } while (pinCode.length() != 4);
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
    readPinCode(
        clientAccount.pinCode
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

void printClientAccountInformationAsLine(
    const ClientAccount& CLIENT_ACCOUNT,
    const string& SEPARATOR = "\\\\"
) {
    cout << CLIENT_ACCOUNT.identifierNumber << SEPARATOR
        << CLIENT_ACCOUNT.pinCode << SEPARATOR
        << CLIENT_ACCOUNT.fullName.firstName << SEPARATOR
        << CLIENT_ACCOUNT.fullName.secondName << SEPARATOR
        << CLIENT_ACCOUNT.mobileNumber.countryCode << SEPARATOR
        << CLIENT_ACCOUNT.mobileNumber.contactNumber << SEPARATOR
        << CLIENT_ACCOUNT.balance;
}

int main() {
    ClientAccount clientAccount;
    readNewClient(
        clientAccount
    );
    printClientAccountInformationAsLine(
        clientAccount
    );
}