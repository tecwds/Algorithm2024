//
// Created by wpan on 10/16/24.
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include <iostream>
using namespace std;

// 类似fib
// 高精度加法
string high_add(string n1, string n2) {
    // 确保 n1 是长的数字
    if (n1.length() < n2.length()) {
        swap(n1, n2);
    }

    // 反转，低位在前
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    string result;
    // 进位
    int carry = 0;

    // 相加
    for (size_t i = 0; i < n1.length(); ++i) {
        int sum = carry;
        sum += n1[i] - '0';

        if (i < n2.length()) {
            sum += n2[i] - '0';
        }

        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    if (carry > 0) {
        result.push_back(carry + '0');
    }

    reverse(result.begin(), result.end());

    return result;
}

string fibonacci(int n) {
    // long long a = 0, b = 1, c;
    string a = "0";
    string b = "1";

    if (n == 0) return a;
    for (int i = 2; i <= n; i++) {
        const string c = high_add(a, b);
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int m;
    int n;
    cin >> m >> n; // 读取输入的M和N

    // 输出从蜂房M到蜂房N的路线数
    cout << fibonacci(n - m + 1) << endl;
    return 0;
}

