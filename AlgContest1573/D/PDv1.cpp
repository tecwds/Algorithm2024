//
// Created by wpan on 10/31/24.
//
#include <cmath>
#include <iostream>
using namespace std;

// 计算价格
double price(int n) {
    if (n < 4) return 10;
    n -= 4;
    if (n < 4) return 10 + n * 2;
    return 18 + ceil(n - 4) * 2.4;
}

double div_p(const int n, const int div) {
    const int div_p_ = n / div;
    if (div == 1) return price(n);
    if (n % div == 0) return price(n / div) * div;
    return price(div_p_) * div + price(n - div_p_ * div);
}

int main(int argc, char *argv[]) {
    int n;

    while (true) {
        cin >> n;
        if (n == 0) break;

        // 贪心
        double min = 10e7;
        for (int i = 1; i <= n; i++) {
            if (const double tmp = div_p(n, i); min > tmp) {
                min = tmp;
            }
        }

        cout << min << endl;
    }

    return 0;
}
