//
// Created by wpan on 12/5/24.
//
#include <iostream>
using namespace std;

int dp(const int m, const int n) {
    if (!m || !n || m == 1 || n == 1) return 1;
    if (m < n) return dp(m, m);
    return dp(m, n - 1) + dp(m - n, n);
}

int main() {
    int t;
    int m;
    int n;

    cin >> t;

    while (t--) {
        cin >> m >> n;
        cout << dp(m, n);
    }

    return 0;
}
