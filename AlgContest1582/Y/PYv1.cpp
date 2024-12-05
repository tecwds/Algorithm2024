//
// Created by wpan on 12/5/24.
//
#include <cstring>
#include <iostream>
using namespace std;

int n;
int x;
int cnt;

int w[200];
int dp[45005];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    while (cin >> n) {
        cnt = 0;
        memset(dp, 0, sizeof dp);

        for (int i = 1; i <= n; ++i) {
            cin >> w[i];
            cnt += w[i];
        }

        x = cnt / 2;

        for (int i = 1; i <= n; i++)
            for (int j = x; j >= w[i]; --j)
                dp[j] = max(dp[j - w[i]] + w[i], dp[j]);
        cout << dp[x] << " " << cnt - dp[x] << endl;
    }

    return 0;
}
