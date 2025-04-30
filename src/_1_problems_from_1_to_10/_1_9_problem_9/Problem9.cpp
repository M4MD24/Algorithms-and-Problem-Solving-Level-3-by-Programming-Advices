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

void printMiddleRowOfMatrixNumbers(
    const short MATRIX_NUMBERS[3][3],
    const short ROWS,
    const short COLUMNS
) {
    const short MIDDLE_ROW = static_cast<short>(ROWS / 2);
    for (int column = 0; column < COLUMNS; ++column)
        cout << MATRIX_NUMBERS[MIDDLE_ROW][column] << ' ';
}

void printMiddleColumnOfMatrixNumbers(
    const short MATRIX_NUMBERS[3][3],
    const short ROWS,
    const short COLUMNS
) {
    const short MIDDLE_COLUMN = static_cast<short>(COLUMNS / 2);
    for (int row = 0; row < ROWS; ++row)
        cout << MATRIX_NUMBERS[row][MIDDLE_COLUMN] << endl;
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
    const short NUMBER_NUMBER_WIDTH = 2;
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
        NUMBER_NUMBER_WIDTH
    );

    cout << "\nMiddle Column of Matrix Numbers:" << endl;
    printMiddleColumnOfMatrixNumbers(
        matrixNumbers,
        ROWS,
        COLUMNS
    );

    cout << "\nMiddle Row of Matrix Numbers:" << endl;
    printMiddleRowOfMatrixNumbers(
        matrixNumbers,
        ROWS,
        COLUMNS
    );
}