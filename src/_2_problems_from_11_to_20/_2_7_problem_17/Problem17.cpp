#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

short randomNumber(
    const short FROM,
    const short TO
) { return rand() % (TO - FROM + 1) + FROM; }

void fillMatrixWithRandomNumbers(
    short matrixNumbers[5][5],
    const short ROWS,
    const short COLUMNS
) {
    for (short row = 0; row < ROWS; ++row)
        for (short column = 0; column < COLUMNS; ++column)
            matrixNumbers[row][column] = randomNumber(
                -9,
                99
            );
}

void printMatrixNumbers(
    const short MATRIX_NUMBERS[5][5],
    const short ROWS,
    const short COLUMNS,
    const short NUMBER_WIDTH
) {
    for (short row = 0; row < ROWS; ++row) {
        for (short column = 0; column < COLUMNS; ++column)
            cout << setw(
                NUMBER_WIDTH
            ) << MATRIX_NUMBERS[row][column] << ' ';
        cout << endl;
    }
}

short readNumber() {
    short number;
    bool valid;
    do {
        cout << "Enter Target Number:" << endl;
        cin >> number;
        valid = !cin.fail();
        if (!valid) {
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );
        }
    } while (!valid);
    return number;
}

bool isTargetNumberFoundInMatrixNumbers(
    const short MATRIX_NUMBERS[5][5],
    const short ROWS,
    const short COLUMNS,
    const short TARGET_NUMBER
) {
    for (short row = 0; row < ROWS; ++row)
        for (short column = 0; column < COLUMNS; ++column)
            if (MATRIX_NUMBERS[row][column] == TARGET_NUMBER)
                return true;
    return false;
}

int main() {
    srand(
        static_cast<unsigned>(
            time(
                nullptr
            )
        )
    );

    const short ROWS = 5,
                COLUMNS = 5;
    const short NUMBER_WIDTH = 2;
    short matrixNumbers[ROWS][COLUMNS];

    fillMatrixWithRandomNumbers(
        matrixNumbers,
        ROWS,
        COLUMNS
    );

    cout << "Matrix Numbers:" << endl;
    printMatrixNumbers(
        matrixNumbers,
        ROWS,
        COLUMNS,
        NUMBER_WIDTH
    );

    cout << endl;

    const short TARGET_NUMBER = readNumber();

    cout << "Number " << TARGET_NUMBER << " Is" << (
        isTargetNumberFoundInMatrixNumbers(
            matrixNumbers,
            ROWS,
            COLUMNS,
            TARGET_NUMBER
        )
            ? ""
            : "n't"
    ) << " Found";
}