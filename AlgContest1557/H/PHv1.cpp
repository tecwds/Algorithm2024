//
// Created by wpan on 10/30/24.
//
#include<bits/stdc++.h>
using namespace std;

constexpr int N = 10086;

long long a[N];
long long sum;
long long n;
long long c;
long long ans;
long long all;

bool flag;

void dfs(const int d, const long long remain) {
    if (sum + remain < ans) return;

    if (flag) return;

    for (int i = d; i <= n; i++) {
        if ((sum + a[i] <= c)) {
            sum += a[i];
            ans = max(ans, sum);
            if (ans == c) {
                flag = true;
                return;
            }
            dfs(i + 1, remain - a[i]);
            sum -= a[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        all += a[i];
    }
    sort(a + 1, a + n + 1);
    dfs(1, all);
    cout << ans << '\n';
    return 0;
}
