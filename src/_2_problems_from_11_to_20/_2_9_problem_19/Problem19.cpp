#include <iomanip>
#include <iostream>
using namespace std;

short randomNumber(
    const short FROM,
    const short TO
) { return rand() % (TO - FROM + 1) + FROM; }

void fillMatrixWithRandomNumbers(
    short matrixNumbers[7][7],
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
    const short MATRIX_NUMBERS[7][7],
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

short minimumNumberInMatrixNumbers(
    const short MATRIX_NUMBERS[7][7],
    const short ROWS,
    const short COLUMNS
) {
    short minimumNumber = MATRIX_NUMBERS[0][0];
    for (short row = 0; row < ROWS; ++row)
        for (short column = 0; column < COLUMNS; ++column)
            if (
                const short CURRENT_NUMBER = MATRIX_NUMBERS[row][column];
                CURRENT_NUMBER < minimumNumber
            )
                minimumNumber = CURRENT_NUMBER;
    return minimumNumber;
}

int main() {
    srand(
        static_cast<unsigned>(
            time(
                nullptr
            )
        )
    );

    const short ROWS = 7,
                COLUMNS = 7;
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

    cout << "\nMinimum Number in Matrix Numbers: " << minimumNumberInMatrixNumbers(
        matrixNumbers,
        ROWS,
        COLUMNS
        );
}