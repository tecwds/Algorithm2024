//
// Created by wpan on 24-9-29.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string high_mul(string n1, string n2) {
    if (n1 == "0" || n2 == "0") return "0";

    // 预分配 n1,n2 位数和的大小空间，同时置0
    vector<size_t> result(n1.size() + n2.size(), 0);

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    // 相乘
    for (size_t i = 0; i < n1.size(); ++i) {
        for (size_t j = 0; j < n2.size(); ++j) {
            const size_t mul = (n1[i] - '0') * (n2[j] - '0');
            const size_t sum = mul + result[i + j];

            result[i + j + 1] += sum / 10;
            result[i + j] = sum % 10;
        }
    }

    string res;
    bool zero_flag = true;
    for (int i = static_cast<int>(result.size()) - 1; i >= 0; --i) {
        if (zero_flag && result[i] == 0) continue;
        zero_flag = false;
        res.push_back('0' + result[i]);
    }
    return res.empty() ? "0" : res;
}

int main() {
    string n1;
    string n2;

    cin >> n1 >> n2;

    cout << high_mul(n1, n2) << endl;
    return 0;
}