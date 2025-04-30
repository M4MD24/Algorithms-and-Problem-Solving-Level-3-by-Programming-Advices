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

int main() {
    const short ROWS = 5,
                COLUMNS = 5;
    const short NUMBER_WIDTH = 2;
    short matrixOrderedNumbers[ROWS][COLUMNS];

    fillMatrixOrderedNumbers(
        matrixOrderedNumbers,
        ROWS,
        COLUMNS
    );

    cout << "Matrix Ordered Numbers:" << endl;
    printMatrixNumbers(
        matrixOrderedNumbers,
        ROWS,
        COLUMNS,
        NUMBER_WIDTH
    );
}