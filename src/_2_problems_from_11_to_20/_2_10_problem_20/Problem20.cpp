#include <cmath>
#include <iomanip>
#include <iostream>
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

short areColumnsPalindromeInMatrixNumbers(
    const short MATRIX_NUMBERS[5][5],
    const short ROWS,
    const short COLUMNS
) {
    const short MIDDLE_ROW = ROWS / 2,
                MIDDLE_COLUMN = COLUMNS / 2;
    for (
        short leftColumn = 0, rightColumn = static_cast<short>(COLUMNS - 1);
        leftColumn < MIDDLE_COLUMN;
        ++leftColumn, --rightColumn
    )
        for (
            short leftRow = 0, rightRow = static_cast<short>(ROWS - 1);
            leftRow < MIDDLE_ROW;
            ++leftRow, --rightRow
        )
            if (MATRIX_NUMBERS[leftRow][leftColumn] != MATRIX_NUMBERS[rightRow][leftColumn])
                return false;
    return true;
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
    const short MATRIX_NUMBERS[ROWS][COLUMNS]{
        {
            1,
            2,
            3,
            2,
            1
        },
        {
            1,
            2,
            3,
            2,
            1
        },
        {
            1,
            2,
            3,
            2,
            1
        },
        {
            1,
            2,
            3,
            2,
            1
        },
        {
            1,
            2,
            3,
            2,
            1
        }
    };

    cout << "Matrix Numbers:" << endl;
    printMatrixNumbers(
        MATRIX_NUMBERS,
        ROWS,
        COLUMNS,
        NUMBER_WIDTH
    );

    cout << "\nAre" << (
        areColumnsPalindromeInMatrixNumbers(
            MATRIX_NUMBERS,
            ROWS,
            COLUMNS
        )
            ? ""
            : "n't"
    ) << " Columns Palindrome in Matrix Numbers";
}