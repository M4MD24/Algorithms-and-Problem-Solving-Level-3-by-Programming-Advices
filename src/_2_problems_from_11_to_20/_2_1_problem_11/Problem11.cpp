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

short calculateSumOfNumbers(
    const short MATRIX_NUMBERS[3][3],
    const short ROWS,
    const short COLUMNS
) {
    short sumOfNumbers = 0;
    for (short row = 0; row < ROWS; ++row)
        for (short column = 0; column < COLUMNS; ++column)
            sumOfNumbers += MATRIX_NUMBERS[row][column];
    return sumOfNumbers;
}

bool areEqualMatrices(
    const short FIRST_MATRIX_NUMBERS[3][3],
    const short SECOND_MATRIX_NUMBERS[3][3],
    const short ROWS,
    const short COLUMNS
) {
    const short SUM_OF_FIRST_NUMBERS = calculateSumOfNumbers(
                    FIRST_MATRIX_NUMBERS,
                    ROWS,
                    COLUMNS
                ),
                SUM_OF_SECOND_NUMBERS = calculateSumOfNumbers(
                    SECOND_MATRIX_NUMBERS,
                    ROWS,
                    COLUMNS
                );
    return SUM_OF_FIRST_NUMBERS == SUM_OF_SECOND_NUMBERS;
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

    cout << "\nSum of Matrices are" << (
        areEqualMatrices(
            firstMatrixNumbers,
            secondMatrixNumbers,
            ROWS,
            COLUMNS
        )
            ? ""
            : "n't"
    ) << " equal";
}