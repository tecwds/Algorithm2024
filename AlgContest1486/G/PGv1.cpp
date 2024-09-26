#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// 计算并返回 A/B 的精确值，精确到小数点后 20 位
string div_(long long a, long long b) {
    string result;
    long long quotient = a / b; // 整数部分
    long long remainder = a % b; // 余数部分

    // 将整数部分添加到结果字符串
    result = to_string(quotient) + ".";

    // 计算小数部分
    for (long long i = 0; i < 20; ++i) {
        remainder *= 10;
        long long digit = remainder / b;
        result += to_string(digit);
        remainder %= b;

        if (remainder == 0) break;
    }

    return result;
}

int main() {
    long long a;
    long long b;

    cin >> a >> b;

    string res = div_(a, b);
    
    // 去零

    int begin = 0;
    int end = res.size();
    for (int i = end - 1; i > begin; --i) {
        if (res[i] == '0' && res[i - 1] != '.') {
            end--;
        } else break;
    }

    cout << a << "/" << b << "=" << res.substr(0, end - begin) << endl;

    return 0;
}