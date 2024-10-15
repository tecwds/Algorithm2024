//
// Created by wpan on 10/15/24.
//
#include <iostream>
#include <vector>

using namespace std;

// 动态规划求解方案数
long long solve(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;  // 空房间也是一种方案
    dp[1] = 1;  // 长度为1的房间只有一种方案

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }

    return dp[n];
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}