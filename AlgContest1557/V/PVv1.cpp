//
// Created by wpan on 10/31/24.
//
#include<bits/stdc++.h>
using namespace std;

int n, m, l, r, p, q, ans, d;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

char mp[105][105];
bool vis[105][105];

void dfs(int x, int y) {
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 1 || ny < 1 || nx > n || ny > m || mp[nx][ny] == 'K')continue;
        if (!vis[nx][ny]) {
            vis[nx][ny] = true;
            if (mp[nx][ny] == '#') {
                d += 2;
                if (nx == p && ny == q)ans = min(ans, d);
                else dfs(nx, ny);
                d -= 2;
            } else {
                d++;
                if (nx == p && ny == q)ans = min(ans, d);
                else dfs(nx, ny);
                d--;
            }
            vis[nx][ny] = false;
        }
    }
}

int main() {
    while (true) {
        cin >> n >> m;
        ans = 1e9;
        d = 0;
        memset(vis, 0, sizeof vis);
        if (n == 0 && m == 0)break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                cin >> mp[i][j];
                if (mp[i][j] == 'S')l = i, r = j;
                if (mp[i][j] == 'T')p = i, q = j;
            }
        dfs(l, r);
        cout << ans << endl;
    }
    return 0;
}
