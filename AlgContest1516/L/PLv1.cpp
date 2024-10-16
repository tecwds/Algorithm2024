//
// Created by wpan on 10/16/24.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    int p;
    cin >> n >> p; // 读取输入的两个整数 n 和 p

    int regions = 2 * p;

    // 接下来计算剩余的n-p条直线
    for (int i = p + 1; i <= n; ++i) {
        regions += i; // 每增加一条直线，增加的区域数等于它与其他直线的交点数加1
    }

    cout << regions << endl; // 输出区域总数，减去1是因为初始区域被计算了两次
    return 0;
}
