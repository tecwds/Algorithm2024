#include <iostream>
using namespace std;

size_t toEight(size_t n, size_t index = 8, size_t pos = 1) {
    size_t carry = n % index;

    if (n) {
        return toEight(n / index, index, pos * 10) + carry * pos;
    }
    return 0;
}


int main() {
    size_t n;

    cin >> n;

    cout << toEight(n) << endl;

    return 0;
}