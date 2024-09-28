//
// Created by wpan on 24-9-28.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <charconv>
using namespace std;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    string res;

    for (int i = 1; i <= n; ++i) {
        res = high_add(res, to_string(i));
    }

    cout << res << endl;

    return 0;
}