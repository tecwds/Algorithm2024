//
// Created by wpan on 12/10/24.
//
#include <iomanip>
#include <iostream>
#include <random>
using namespace std;

double darts(const long long n) {
    long long k = 0;
    static default_random_engine e(time(nullptr));
    static uniform_real_distribution<> u(0, 1);

    for (int i = 1; i <= n; ++i) {
        const double x = u(e);
        const double y = u(e);

        if (x * x + y * y <= 1) {
            k++;
        }
    }
    cout << fixed << setprecision(5) << 4.0 * k / n << endl;
    return 0;
}

int main() {
    darts(330000);
    return 0;
}
