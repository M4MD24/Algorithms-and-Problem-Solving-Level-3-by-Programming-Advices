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
    const int NUMBER_COUNT,
    const long long CURRENT = 1,
    const long long PREVIOUS = 0
) {
    if (NUMBER_COUNT < 1)
        return;
    cout << CURRENT << ' ';
    printFibonacciSeries(
        NUMBER_COUNT - 1,
        PREVIOUS + CURRENT,
        CURRENT
    );
}

int main() {
    const int NUMBER_COUNT = readPositiveNumber();
    cout << "Fibonacci Series:" << endl;
    printFibonacciSeries(
        NUMBER_COUNT
    );
}