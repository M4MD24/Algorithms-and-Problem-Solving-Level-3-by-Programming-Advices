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
                -9,
                99
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

void multiplyMatricesNumbers(
    short matrixMultiplyNumbers[3][3],
    const short FIRST_MATRIX_NUMBERS[3][3],
    const short SECOND_MATRIX_NUMBERS[3][3],
    const short ROWS,
    const short COLUMNS
) {
    for (short row = 0; row < ROWS; ++row)
        for (short column = 0; column < COLUMNS; ++column)
            matrixMultiplyNumbers[row][column] = static_cast<short>(FIRST_MATRIX_NUMBERS[row][column] * SECOND_MATRIX_NUMBERS[row][column]);
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
    const short MATRICES_NUMBERS_NUMBER_WIDTH = 2,
                MATRIX_MULTIPLY_NUMBERS_NUMBER_WIDTH = 4;
    short firstMatrixNumbers[ROWS][COLUMNS];
    short secondMatrixNumbers[ROWS][COLUMNS];
    short matrixMultiplyNumbers[ROWS][COLUMNS];

    fillMatrixWithRandomNumbers(
        firstMatrixNumbers,
        ROWS,
        COLUMNS
    );

    fillMatrixWithRandomNumbers(
        secondMatrixNumbers,
        ROWS,
        COLUMNS
    );

    cout << "First Matrix Numbers:" << endl;
    printMatrixNumbers(
        firstMatrixNumbers,
        ROWS,
        COLUMNS,
        MATRICES_NUMBERS_NUMBER_WIDTH
    );

    cout << "Second Matrix Numbers:" << endl;
    printMatrixNumbers(
        secondMatrixNumbers,
        ROWS,
        COLUMNS,
        MATRICES_NUMBERS_NUMBER_WIDTH
    );

    multiplyMatricesNumbers(
        matrixMultiplyNumbers,
        firstMatrixNumbers,
        secondMatrixNumbers,
        ROWS,
        COLUMNS
    );

    cout << "Matrix Multiply Numbers" << endl;
    printMatrixNumbers(
        matrixMultiplyNumbers,
        ROWS,
        COLUMNS,
        MATRIX_MULTIPLY_NUMBERS_NUMBER_WIDTH
    );
}