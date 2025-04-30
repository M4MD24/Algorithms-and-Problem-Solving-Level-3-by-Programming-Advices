#include <cmath>
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
                0,
                1
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

short countOfTargetNumberInMatrixNumbers(
    const short MATRIX_NUMBERS[5][5],
    const short ROWS,
    const short COLUMNS,
    const short TARGET_NUMBER
) {
    short counter = 0;
    for (short row = 0; row < ROWS; ++row)
        for (short column = 0; column < COLUMNS; ++column)
            if (MATRIX_NUMBERS[row][column] == TARGET_NUMBER)
                counter++;
    return counter;
}

short isSparseMatrix(
    const short MATRIX_NUMBERS[5][5],
    const short ROWS,
    const short COLUMNS
) {
    const short NUMBER_COUNT = static_cast<short>(ROWS * COLUMNS);
    return countOfTargetNumberInMatrixNumbers(
        MATRIX_NUMBERS,
        ROWS,
        COLUMNS,
        0
    ) >= ceil(
        static_cast<float>(NUMBER_COUNT) / 2
    );
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
    const short NUMBER_WIDTH = 1;
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

    cout << "\nIs" << (
        isSparseMatrix(
            matrixNumbers,
            ROWS,
            COLUMNS
        )
            ? ""
            : "n't"
    ) << " Sparse Matrix";
}