//
// Created by wpan on 10/30/24.
//
#include<bits/stdc++.h>
using namespace std;

int w, h, p, q, ans, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

char mp[25][25];
bool vis[25][25];

void dfs(int x, int y) {
    ans++;
    vis[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 1 || ny < 1 || nx > w || ny > h)continue;
        if (!vis[nx][ny] && mp[nx][ny] == '.')dfs(nx, ny);
    }
}

int main() {
    while (1) {
        memset(vis, 0, sizeof vis);
        cin >> h >> w;
        ans = 0;
        if (w == 0 && h == 0)break;
        for (int i = 1; i <= w; i++)
            for (int j = 1; j <= h; j++) {
                cin >> mp[i][j];
                if (mp[i][j] == '@')p = i, q = j, mp[i][j] = '.';
            }
        dfs(p, q);
        cout << ans << '\n';
    }
    return 0;
}
