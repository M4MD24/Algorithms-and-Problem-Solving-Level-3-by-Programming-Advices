#include <iostream>
#include <limits>
using namespace std;

int readPositiveNumber() {
    int number;
    bool valid;
    do {
        cout << "Enter positive number:" << endl;
        cin >> number;
        valid = !cin.fail();
        if (!valid) {
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );
        }
    } while (number < 1 || !valid);
    return number;
}

void printFibonacciSeries(
    const int NUMBER_COUNT
) {
    long long previous = 1,
              current = 1;
    cout << previous;
    for (int index = 1; index < NUMBER_COUNT; ++index) {
        cout << ' ' << current;
        const long long NEXT_TERM = previous + current;
        previous = current;
        current = NEXT_TERM;
    }
    cout << endl;
}

int main() {
    const int NUMBER_COUNT = readPositiveNumber();
    cout << "Fibonacci Series:" << endl;
    printFibonacciSeries(
        NUMBER_COUNT
    );
}