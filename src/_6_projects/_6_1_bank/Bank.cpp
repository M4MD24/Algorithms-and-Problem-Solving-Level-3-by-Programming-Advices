#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>
#include "Constants.h"
using namespace std;
using namespace Constants;

enum MainMenuChoice {
    CreateNewClientAccount = 1,
    ShowClientAccountList = 2,
    UpdateClientAccount = 3,
    DeleteClientAccount = 4,
    FindClientAccount = 5,
    Transactions = 6,
    ExitProgram = 7
};

enum TransactionsChoice {
    Deposit = 1,
    Withdraw = 2,
    TotalBalances = 3,
    BackToMainMenu = 4
};

enum FileRequest {
    Update = 1,
    Delete = 2
};

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

void displayMainMenu() {
    cout << "Main Menu:" << endl
        << "[1] Create New Client Account" << endl
        << "[2] Show Client Account List" << endl
        << "[3] Update Client Account" << endl
        << "[4] Delete Client Account" << endl
        << "[5] Find Client Account" << endl
        << "[6] Transactions" << endl
        << "[7] Exit Program" << endl;
}

void displayTransactionsMenu() {
    cout << "Transactions Menu:" << endl
        << "[1] Deposit" << endl
        << "[2] Withdraw" << endl
        << "[3] Total Balances" << endl
        << "[4] Back to Main Menu" << endl;
}

bool isNumber(
    short& number
) {
    cin >> number;
    if (
        const bool VALID = !cin.fail();
        !VALID
    ) {
        cin.clear();
        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );
        return false;
    }
    return true;
}

bool isPositiveNumber(
    const short& NUMBER
) { return NUMBER > 0; }

short readNumber(
    const short& FROM,
    const short& TO
) {
    short number;
    do cout << "Enter number [" << FROM << ":" << TO << "]" << endl;
    while (
        !isNumber(
            number
        ) && isPositiveNumber(
            number
        )
    );
    return number;
}

bool isPositiveNumber(
    const long double& NUMBER
) { return NUMBER > 0; }

string readText(
    const string& INPUT_TYPE_NAME
) {
    cout << "Enter " << INPUT_TYPE_NAME << ":" << endl;
    string TEXT;
    cin >> TEXT;
    return TEXT;
}

void readIdentifierNumber(
    string& identifierNumber
) {
    identifierNumber = readText(
        "Identifier Number"
    );
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

void readBalance(
    long double& balance
) {
    cout << "Enter Balance" << endl;
    cin >> balance;
}

void readClientAccount(
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

string convertFromRecordToLine(
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

void saveClientAccountLineToFile(
    const string& CLIENT_ACCOUNT_LINE
) {
    fstream file(
        CLIENT_ACCOUNTS_PATH,
        ios::out | ios::app
    );
    if (file.is_open())
        file << CLIENT_ACCOUNT_LINE << endl;
    file.close();
}

void createNewClientAccount() {
    ClientAccount clientAccount;

    readClientAccount(
        clientAccount
    );

    const string CLIENT_ACCOUNT_LINE = convertFromRecordToLine(
        clientAccount
    );

    saveClientAccountLineToFile(
        CLIENT_ACCOUNT_LINE
    );

    cout << "Client account has been created successfully." << endl;
}

void printHeader() {
    cout << TABLE_LINE << endl;
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
    cout << endl << TABLE_LINE << endl;
}

void printBody(
    const ClientAccount& CLIENT_ACCOUNT
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
    ) << fixed << setprecision(
        BALANCE_PRECISION
    ) << CLIENT_ACCOUNT.balance << " |";
    cout << endl << TABLE_LINE << endl;
}

void printClientAccountRecordsTable(
    const ClientAccount& CLIENT_ACCOUNT
) {
    printHeader();
    printBody(
        CLIENT_ACCOUNT
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

void readIdentifierNumber(
    string& identifierNumber,
    const string& IDENTIFIER_NUMBER_FIELD
) { identifierNumber = IDENTIFIER_NUMBER_FIELD; }

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
    if (FIELDS.size() == 7) {
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
}

void showClientAccountList() {
    fstream file(
        CLIENT_ACCOUNTS_PATH,
        ios::in
    );

    printHeader();

    size_t counter = 0;
    if (file.is_open()) {
        string clientAccountLine;
        while (
            getline(
                file,
                clientAccountLine
            )
        ) {
            counter++;

            ClientAccount clientAccount;

            readClientAccountFields(
                clientAccount,
                readClientAccountByLine(
                    clientAccountLine
                )
            );

            printBody(
                clientAccount
            );
        }
        file.close();
    }

    cout << "Count of Client Accounts = " << counter << " Client(s)" << endl;
}

void printExitProgramMessage(
    const string& EXIT_PROGRAM_MESSAGE
) { cout << EXIT_PROGRAM_MESSAGE; }

void updateClientAccount(
    ClientAccount& clientAccount
) {
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

vector<string> readClientAccountLinesInFile(
    const string& FILE_PATH
) {
    fstream file(
        FILE_PATH,
        ios::in
    );

    vector<string> clientAccountLines;

    if (file.is_open()) {
        string line;
        while (
            getline(
                file,
                line
            )
        )
            clientAccountLines.push_back(
                line
            );
        file.close();
    }

    return clientAccountLines;
}

bool whatDoYouNeedForFile(
    const string& REQUEST
) {
    string accepting;
    const string ACCEPT_TEXT = "yes",
                 REJECT_TEXT = "no";
    do {
        cout << "Do you want " << REQUEST << " it? (" << ACCEPT_TEXT << '/' << REJECT_TEXT << ")" << endl;
        cin >> accepting;
    } while (
        accepting != ACCEPT_TEXT &&
        accepting != REJECT_TEXT
    );
    return accepting == ACCEPT_TEXT;
}

string checkFileRequest(
    const FileRequest& REQUEST
) {
    if (REQUEST == Update)
        return "Update";
    return "Delete";
}

void updateClientAccountByIdentifierNumber(
    const ClientAccount& CLIENT_ACCOUNT,
    const bool isTransaction
) {
    if (
        const string CLIENT_ACCOUNT_IDENTIFIER_NUMBER = CLIENT_ACCOUNT.identifierNumber;
        !CLIENT_ACCOUNT_IDENTIFIER_NUMBER.empty()
    )
        if (
            whatDoYouNeedForFile(
                checkFileRequest(
                    Update
                )
            )
        ) {
            vector<string> clientAccountLines = readClientAccountLinesInFile(
                CLIENT_ACCOUNTS_PATH
            );

            vector<string> updatedClientAccountLines;

            for (string& clientAccountLine : clientAccountLines) {
                ClientAccount currentClientAccount;

                const vector<string> CLIENT_ACCOUNT_FIELDS = readClientAccountByLine(
                    clientAccountLine
                );

                readClientAccountFields(
                    currentClientAccount,
                    CLIENT_ACCOUNT_FIELDS
                );

                if (currentClientAccount.identifierNumber == CLIENT_ACCOUNT_IDENTIFIER_NUMBER) {
                    if (!isTransaction) {
                        updateClientAccount(
                            currentClientAccount
                        );
                        updatedClientAccountLines.push_back(
                            convertFromRecordToLine(
                                currentClientAccount
                            )
                        );
                    } else
                        updatedClientAccountLines.push_back(
                            convertFromRecordToLine(
                                CLIENT_ACCOUNT
                            )
                        );
                } else
                    updatedClientAccountLines.push_back(
                        clientAccountLine
                    );
            }

            fstream file(
                CLIENT_ACCOUNTS_PATH,
                ios::out | ios::trunc
            );

            for (const string& UPDATED_LINE : updatedClientAccountLines)
                file << UPDATED_LINE << endl;

            file.close();

            cout << "Client account has been updated successfully." << endl;
        }
}

void deleteClientAccountByIdentifierNumber(
    const ClientAccount& CLIENT_ACCOUNT
) {
    if (
        const string CLIENT_ACCOUNT_IDENTIFIER_NUMBER = CLIENT_ACCOUNT.identifierNumber;
        !CLIENT_ACCOUNT_IDENTIFIER_NUMBER.empty()
    )
        if (
            whatDoYouNeedForFile(
                checkFileRequest(
                    Delete
                )
            )
        ) {
            vector<string> clientAccountLines = readClientAccountLinesInFile(
                CLIENT_ACCOUNTS_PATH
            );

            fstream file(
                CLIENT_ACCOUNTS_PATH,
                ios::out | ios::trunc
            );

            for (string& clientAccountLine : clientAccountLines) {
                const string CURRENT_IDENTIFIER_NUMBER = readClientAccountByLine(
                    clientAccountLine
                )[0];

                if (CURRENT_IDENTIFIER_NUMBER != CLIENT_ACCOUNT_IDENTIFIER_NUMBER)
                    file << clientAccountLine << endl;
            }

            file.close();

            cout << "Client account has been deleted successfully." << endl;
        }
}

ClientAccount findClientAccountByIdentifierNumber(
    const bool DISPLAY_CLIENT_ACCOUNT_INFORMATION
) {
    string identifierNumberTarget;
    readIdentifierNumber(
        identifierNumberTarget
    );

    fstream file(
        CLIENT_ACCOUNTS_PATH,
        ios::in
    );

    if (file.is_open()) {
        string clientAccountLine;
        while (
            getline(
                file,
                clientAccountLine
            )
        ) {
            const string CURRENT_IDENTIFIER_NUMBER = readClientAccountByLine(
                clientAccountLine
            )[0];

            if (CURRENT_IDENTIFIER_NUMBER == identifierNumberTarget) {
                cout << "Is Found" << endl;

                ClientAccount clientAccount;
                readClientAccountFields(
                    clientAccount,
                    readClientAccountByLine(
                        clientAccountLine
                    )
                );

                if (DISPLAY_CLIENT_ACCOUNT_INFORMATION) {
                    printHeader();
                    printBody(
                        clientAccount
                    );
                }

                return clientAccount;
            }
        }

        file.close();

        cout << "Isn't Found" << endl;
    }

    return ClientAccount{};
}

void printBalance(
    const long double BALANCE
) {
    cout << "Current Balance = " << fixed << setprecision(
        BALANCE_PRECISION
    ) << BALANCE << endl;
}

bool areYourSure() {
    string accepting;
    const string ACCEPT_TEXT = "yes",
                 REJECT_TEXT = "no";
    do {
        cout << "Are your sure?" << endl;
        cin >> accepting;
    } while (
        accepting != ACCEPT_TEXT &&
        accepting != REJECT_TEXT
    );
    return accepting == ACCEPT_TEXT;
}

long double readAmount() {
    long double amount;
    do {
        readBalance(
            amount
        );
    } while (
        !isPositiveNumber(
            amount
        ) && !areYourSure()
    );
    return amount;
}

void withdraw(
    ClientAccount clientAccount
) {
    long double& balance = clientAccount.balance;

    const long double AMOUNT = readAmount();

    balance -= AMOUNT;

    updateClientAccountByIdentifierNumber(
        clientAccount,
        true
    );
}

void deposit(
    ClientAccount clientAccount
) {
    long double& balance = clientAccount.balance;

    const long double AMOUNT = readAmount();

    balance += AMOUNT;

    updateClientAccountByIdentifierNumber(
        clientAccount,
        true
    );
}

void printTotalBalancesHeader() {
    cout << TOTAL_BALANCES_TABLE_LINE << endl;
    cout << "| " << setw(
        20
    ) << "Identifier Number";
    cout << " | " << setw(
        30
    ) << "Full Name";
    cout << " | " << setw(
        20
    ) << "Balance" << " |";
    cout << endl << TOTAL_BALANCES_TABLE_LINE << endl;
}

void printTotalBalancesBody(
    const ClientAccount& CLIENT_ACCOUNT
) {
    cout << "| " << setw(
        20
    ) << CLIENT_ACCOUNT.identifierNumber;
    cout << " | " << setw(
        30
    ) << CLIENT_ACCOUNT.fullName.firstName + " " + CLIENT_ACCOUNT.fullName.secondName;
    cout << " | " << setw(
        20
    ) << fixed << setprecision(
        BALANCE_PRECISION
    ) << CLIENT_ACCOUNT.balance << " |";
    cout << endl << TOTAL_BALANCES_TABLE_LINE << endl;
}

void printTotalBalances(
    const vector<string>& CLIENT_ACCOUNT_LINES
) {
    long double totalBalances = 0.0;

    printTotalBalancesHeader();

    for (const string& CLIENT_ACCOUNT_LINE : CLIENT_ACCOUNT_LINES) {
        ClientAccount clientAccount;

        readClientAccountFields(
            clientAccount,
            readClientAccountByLine(
                CLIENT_ACCOUNT_LINE
            )
        );

        totalBalances += clientAccount.balance;

        printTotalBalancesBody(
            clientAccount
        );
    }

    cout << "Total Balances = " << totalBalances << endl;
}

void performTransactionMenu() {
    do {
        displayTransactionsMenu();
        constexpr short START_NUMBER = 1,
                        END_NUMBER = 4;
        const short CHOICE = readNumber(
            START_NUMBER,
            END_NUMBER
        );
        switch (static_cast<TransactionsChoice>(CHOICE)) {
        case Deposit:
            deposit(
                findClientAccountByIdentifierNumber(
                    true
                )
            );
            cout << endl;
            break;
        case Withdraw:
            withdraw(
                findClientAccountByIdentifierNumber(
                    true
                )
            );
            cout << endl;
            break;
        case TotalBalances:
            printTotalBalances(
                readClientAccountLinesInFile(
                    CLIENT_ACCOUNTS_PATH
                )
            );
            cout << endl;
            break;
        case BackToMainMenu:
            return;
        default: ;
        }
    } while (true);
}

void performMainMenu() {
    do {
        displayMainMenu();
        constexpr short START_NUMBER = 1,
                        END_NUMBER = 7;
        const short CHOICE = readNumber(
            START_NUMBER,
            END_NUMBER
        );
        switch (static_cast<MainMenuChoice>(CHOICE)) {
        case CreateNewClientAccount:
            createNewClientAccount();
            cout << endl;
            break;
        case ShowClientAccountList:
            showClientAccountList();
            cout << endl;
            break;
        case UpdateClientAccount:
            updateClientAccountByIdentifierNumber(
                findClientAccountByIdentifierNumber(
                    true
                ),
                false
            );
            cout << endl;
            break;
        case DeleteClientAccount:
            deleteClientAccountByIdentifierNumber(
                findClientAccountByIdentifierNumber(
                    true
                )
            );
            cout << endl;
            break;
        case FindClientAccount:
            findClientAccountByIdentifierNumber(
                true
            );
            cout << endl;
            break;
        case Transactions:
            performTransactionMenu();
            break;
        case ExitProgram:
            printExitProgramMessage(
                "Salam!"
            );
            exit(
                0
            );
        default: ;
        }
    } while (true);
}

void startProgram() { performMainMenu(); }

int main() { startProgram(); }