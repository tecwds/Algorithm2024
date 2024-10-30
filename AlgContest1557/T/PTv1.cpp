//
// Created by wpan on 10/31/24.
//
#include<bits/stdc++.h>
using namespace std;

int n;
int m;
int cnt;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

char mp[105][105];
bool vis[105][105];

void dfs(const int x, const int y) {
    vis[x][y] = true;
    for (int k = 0; k < 8; k++) {
        const int nx = x + dx[k];
        const int ny = y + dy[k];
        if (nx < 1 || ny < 1 || nx > n || ny > m)continue;
        if (!vis[nx][ny] && mp[nx][ny] == '$')dfs(nx, ny);
    }
}

int main() {
    while (true) {
        cnt = 0;
        memset(vis, 0, sizeof vis);
        cin >> n >> m;
        if (n == 0 || m == 0)break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)cin >> mp[i][j];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (mp[i][j] == '$' && !vis[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
            }
        cout << cnt << endl;
    }
    return 0;
}
