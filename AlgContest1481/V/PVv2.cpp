#include <iostream>
#include <vector>

// 高精度乘法函数，将大数v乘以一个整数num
void bigIntMultiply(std::vector<int>& v, int num) {
    int carry = 0; // 进位
    for (size_t i = 0; i < v.size(); i++) {
        int product = v[i] * num + carry;
        v[i] = product % 10; // 保留当前位
        carry = product / 10; // 计算进位
    }
    // 处理剩余的进位
    while (carry) {
        v.push_back(carry % 10);
        carry /= 10;
    }
}

// 高精度阶乘函数
std::vector<int> factorial(int n) {
    std::vector<int> result = {1}; // 初始化结果为1
    for (int i = 2; i <= n; i++) {
        bigIntMultiply(result, i);
    }
    return result;
}

int main() {
    int n;
    std::cin >> n; // 输入要计算的阶乘数
    std::vector<int> result = factorial(n);
    // 输出结果，由于vector中是逆序存储的，所以需要反向输出
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
    return 0;
}
