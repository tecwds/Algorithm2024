//
// Created by wpan on 10/30/24.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int ans = 1e9;
        int n;
        cin >> n;
        int a, b, c;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= a; b++) {
                if (a * b > n)continue;
                for (int c = 1; c <= b; c++) {
                    if (a * b * c == n) {
                        int res = (a * b + a * c + b * c) * 2;
                        ans = min(ans, res);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
