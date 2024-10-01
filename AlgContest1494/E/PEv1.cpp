//
// Created by wpan on 10/1/24.
//
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

double f(const double x, const double a,
         const double b, const double c,
         const double d) {
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

// 二分法寻找根
double find_root(double left, double right,
                 const double a, const double b,
                 const double c, const double d) {
    double mid = 0;
    while (right - left > 1e-7) {
        mid = (left + right) / 2.0;
        if (f(left, a, b, c, d) * f(mid, a, b, c, d) <= 0)
            right = mid;
        else
            left = mid;
    }
    return mid;
}

int main() {
    double a;
    double b;
    double c;
    double d;

    cin >> a >> b >> c >> d;

    vector<double> roots;

    // 在[-100, 100]范围内枚举并寻找根
    for (double x = -100; x <= 100; x += 1) {
        if (f(x, a, b, c, d) * f(x + 1, a, b, c, d) <= 0) {
            // 判断是否跨过0
            double root = find_root(x, x + 1, a, b, c, d);
            roots.push_back(root);
        }
    }

    // 排序根
    sort(roots.begin(), roots.end());

    // 确保根之间的差值大于等于1
    vector<double> valid_roots;
    for (double root: roots) {
        if (valid_roots.empty() || fabs(root - valid_roots.back()) >= 1) {
            valid_roots.push_back(root);
        }
    }

    // 格式化输出
    for (size_t i = 0; i < valid_roots.size(); ++i) {
        cout << fixed << setprecision(2) << valid_roots[i];
        if (i < valid_roots.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
