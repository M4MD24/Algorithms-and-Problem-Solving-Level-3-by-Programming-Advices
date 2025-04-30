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

bool isIdentityMatrix(
    const short MATRIX_NUMBERS[3][3],
    const short ROWS,
    const short COLUMNS
) {
    for (short row = 0; row < ROWS; ++row)
        for (short column = 0; column < COLUMNS; ++column) {
            if (row == column && MATRIX_NUMBERS[row][column] != 1)
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
            1,
            0,
            0
        },
        {
            0,
            1,
            0
        },
        {
            0,
            0,
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

    cout << "\nIs" << (
        isIdentityMatrix(
            MATRIX_NUMBERS,
            ROWS,
            COLUMNS
        )
            ? ""
            : "n't"
    ) << " Identity Matrix";
}