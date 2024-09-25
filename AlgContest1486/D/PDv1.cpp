#include <iostream>
#include <cmath>
using namespace std;

int pow_get_3last(int base, int index) {
    long long result = 1;
    long long base_ = base % 1000;

    while (index > 0) {
        if (index % 2 == 1) {
            result = (result * base_) % 1000;
        }
        base_ = (base_ * base_) % 1000;
        index >>= 1;
    }

    return static_cast<int>(result % 1000);
}

int main() {

    int a;
    
    cin >> a;

    int n = 1;
    int m = 2;

    while (1) {
        if (pow_get_3last(a, m) == pow_get_3last(a, n)) {
            cout << n << " " << m << endl;
            break;
        }
        m++;
        if (m == n) {
            n++;
            m = n + 1;
        }
    }

    return 0;
}