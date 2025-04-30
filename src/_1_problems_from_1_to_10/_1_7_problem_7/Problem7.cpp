#include <iomanip>
#include <iostream>
using namespace std;

void fillMatrixOrderedNumbers(
    short matrixOrderedNumbers[5][5],
    const short ROWS,
    const short COLUMNS
) {
    short counter = 1;
    for (short row = 0; row < ROWS; ++row)
        for (short column = 0; column < COLUMNS; ++column)
            matrixOrderedNumbers[row][column] = counter++;
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

void transposeMatrixNumbers(
    const short MATRIX_NUMBERS[5][5],
    short transposedMatrixNumbers[5][5],
    const short ROWS,
    const short COLUMNS
) {
    for (short row = 0; row < ROWS; ++row)
        for (short column = 0; column < COLUMNS; ++column)
            transposedMatrixNumbers[row][column] = MATRIX_NUMBERS[column][row];
}

int main() {
    const short ROWS = 5,
                COLUMNS = 5;
    const short NUMBER_WIDTH = 2;
    short matrixNumbers[ROWS][COLUMNS];
    short transposedMatrixNumbers[ROWS][COLUMNS];

    fillMatrixOrderedNumbers(
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

    transposeMatrixNumbers(
        matrixNumbers,
        transposedMatrixNumbers,
        ROWS,
        COLUMNS
    );

    cout << "\nTransposed Matrix Numbers:" << endl;
    printMatrixNumbers(
        transposedMatrixNumbers,
        ROWS,
        COLUMNS,
        NUMBER_WIDTH
    );
}