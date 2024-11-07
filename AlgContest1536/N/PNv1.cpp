//
// Created by wpan on 10/20/24.
//
#include <iostream>
#include <vector>

using namespace std;

// 函数用于判断是否可以清空两堆硬币
bool canClear(int a, int b) {
    // 当两堆硬币数量相等时，无法通过一次操作同时减少两堆硬币
    if (a == b) return false;

    // 保证a是较小的一堆
    if (a > b) swap(a, b);

    // 当a为0时，判断b是否为偶数，因为只有当b为偶数时，我们才能通过每次从b中移除2枚硬币来清空它
    if (a == 0) return (b % 2 == 0);

    // 当b是a的两倍加上1或更多时，可以通过一系列操作清空两堆硬币
    while (a > 0 && b > 0) {
        if (b == a * 2) return false; // 如果b正好是a的两倍，则无法通过操作清空
        if (b > a * 2) b -= a * 2; // 如果b大于a的两倍，则从b中移除a的两倍
        else a -= b; // 否则，从a中移除b
    }

    // 如果任一堆硬币数量为0，则可以清空两堆硬币
    return (a == 0 || b == 0);
}

int main() {
    int t;
    cin >> t;

    vector<int> results;

    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;

        if (canClear(a, b)) {
            results.push_back(1);
        } else {
            results.push_back(0);
        }
    }

    for (int result : results) {
        if (result) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
