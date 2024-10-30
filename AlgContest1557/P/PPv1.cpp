//
// Created by wpan on 10/31/24.
//
#include<bits/stdc++.h>
using namespace std;

int n;
int o;
int ans;

char mp[10][10];
bool vis[10][10];
int b[10];
int c[10];

void dfs(const int d, const int remain) {
    if (d > n + 1) return;

    if (remain < 0) return;

    if (d == n + 1 && remain == 0) {
        ans++;
    } else {
        dfs(d + 1, remain);
        for (int k = 1; k <= n; k++) {
            if (mp[d][k] == '#' && !vis[d][k]) {
                if (!b[d] && !c[k]) {
                    vis[d][k] = 1;
                    b[d] = true;
                    c[k] = true;
                    dfs(d + 1, remain - 1);
                    b[d] = false;
                    c[k] = false;
                    vis[d][k] = false;
                }
            }
        }
    }
}

int main() {
    while (cin >> n >> o) {
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);
        ans = 0;
        if (n == -1 && o == -1)break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                cin >> mp[i][j];
            }
        dfs(1, o);
        cout << ans << '\n';
    }
    return 0;
}
