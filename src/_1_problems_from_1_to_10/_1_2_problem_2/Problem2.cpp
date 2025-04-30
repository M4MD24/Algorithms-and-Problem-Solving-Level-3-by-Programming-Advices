#include <iomanip>
#include <iostream>
using namespace std;

short randomNumber(
    const short FROM,
    const short TO
) { return rand() % (TO - FROM + 1) + FROM; }

void fillMatrixWithRandomNumbers(
    short matrixNumbers[3][3],
    const short ROWS,
    const short COLUMNS
) {
    for (short row = 0; row < ROWS; ++row)
        for (short column = 0; column < COLUMNS; ++column)
            matrixNumbers[row][column] = randomNumber(
                -99,
                999
            );
}

void printMatrixNumbers(
    const short MATRIX_NUMBERS[3][3],
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

void printSumEachRowMatrixNumbers(
    const short MATRIX_NUMBERS[3][3],
    const short ROWS,
    const short COLUMNS
) {
    for (short row = 0; row < ROWS; ++row) {
        cout << "Row " << row + 1 << " Sum = ";
        short rowSum = MATRIX_NUMBERS[row][0];
        for (short column = 1; column < COLUMNS; ++column)
            rowSum += MATRIX_NUMBERS[row][column];
        cout << rowSum << endl;
    }
}

int main() {
    srand(
        static_cast<unsigned>(
            time(
                nullptr
            )
        )
    );

    const short ROWS = 3,
                COLUMNS = 3;
    const short NUMBER_WIDTH = 3;
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

    printSumEachRowMatrixNumbers(
        matrixNumbers,
        ROWS,
        COLUMNS
    );
}