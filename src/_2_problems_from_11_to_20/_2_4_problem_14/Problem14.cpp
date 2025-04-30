#include <iomanip>
#include <iostream>
using namespace std;

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

bool isScalarMatrix(
    const short MATRIX_NUMBERS[3][3],
    const short ROWS,
    const short COLUMNS
) {
    const short TARGET_NUMBER = MATRIX_NUMBERS[0][0];
    for (int row = 0; row < ROWS; ++row)
        for (int column = 0; column < COLUMNS; ++column) {
            if (row == column && MATRIX_NUMBERS[row][column] != TARGET_NUMBER)
                return false;
            if (row != column && MATRIX_NUMBERS[row][column] != 0)
                return false;
        }
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

    const short ROWS = 3,
                COLUMNS = 3;
    const short NUMBER_WIDTH = 2;
    const short MATRIX_NUMBERS[ROWS][COLUMNS]{
        {
            9,
            0,
            0
        },
        {
            0,
            9,
            0
        },
        {
            0,
            0,
            9
        }
    };

    cout << "Matrix Numbers:" << endl;
    printMatrixNumbers(
        MATRIX_NUMBERS,
        ROWS,
        COLUMNS,
        NUMBER_WIDTH
    );

    cout << "\nIs" << (
        isScalarMatrix(
            MATRIX_NUMBERS,
            ROWS,
            COLUMNS
        )
            ? ""
            : "n't"
    ) << " Scalar Matrix";
}