//
// Created by wpan on 10/15/24.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 大数加法函数
string addBigInt(const string& num1, const string& num2) {
    string result;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

// 解决问题的函数
string solve(const int n) {
    if (n == 0) return "1";
    if (n == 1) return "1";
    if (n == 2) return "2";

    string a = "1", b = "1", c = "2";
    for (int i = 3; i <= n; i++) {
        string d = addBigInt(a, addBigInt(b, c));
        a = b;
        b = c;
        c = d;
    }

    return c;
}

int main() {
    int n;
    while (cin >> n) {
        cout << solve(n) << endl;
    }

    return 0;
}
