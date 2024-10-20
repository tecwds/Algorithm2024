//
// Created by wpan on 24-9-29.
//
#include <iostream>
#include <string>
#include <algorithm>
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

bool check_input_str(string &input) {
    return all_of(
        input.begin(),
        input.end(),
        [](const char i) {
            return isdigit(i);
        });
}

int main() {
    string s1;
    string s2;

    cin >> s1 >> s2;

    // if (!check_input_str(s1) || !check_input_str(s2)) {
    //     cout << "input error!" << endl;
    //     return 0;
    // }

    cout << high_add(s1, s2) << endl;

    return 0;
}
