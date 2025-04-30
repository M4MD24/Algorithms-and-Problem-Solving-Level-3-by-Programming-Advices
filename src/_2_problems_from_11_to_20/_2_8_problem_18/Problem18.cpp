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

void printIntersectedNumbers(
    const short FIRST_MATRIX_NUMBERS[7][7],
    const short SECOND_MATRIX_NUMBERS[7][7],
    const short ROWS,
    const short COLUMNS
) {
    for (int row = 0; row < ROWS; ++row)
        for (int column = 0; column < COLUMNS; ++column)
            if (
                const short FIRST_NUMBER = FIRST_MATRIX_NUMBERS[row][column],
                            SECOND_NUMBER = SECOND_MATRIX_NUMBERS[row][column];
                FIRST_NUMBER == SECOND_NUMBER
            )
                cout << SECOND_NUMBER << ' ';
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
    short firstMatrixNumbers[ROWS][COLUMNS],
          secondMatrixNumbers[ROWS][COLUMNS];

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
        NUMBER_WIDTH
    );

    cout << "\nSecond Matrix Numbers:" << endl;
    printMatrixNumbers(
        secondMatrixNumbers,
        ROWS,
        COLUMNS,
        NUMBER_WIDTH
    );

    cout << "\nIntersected Numbers:" << endl;
    printIntersectedNumbers(
        firstMatrixNumbers,
        secondMatrixNumbers,
        ROWS,
        COLUMNS
    );
}