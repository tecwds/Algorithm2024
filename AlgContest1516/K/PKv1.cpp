//
// Created by wpan on 10/16/24.
//
#include <iostream>
using namespace std;

// 类似斐波那契
// 计算斐波那契数列的第n项
long long fibonacci(int n) {
    long long a = 0, b = 1, c;
    if (n == 0)
        return a;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cin >> n; // 读取输入的自然数n
    cout << fibonacci(n) << endl; // 输出n个月后兔子的对数
    return 0;
}
