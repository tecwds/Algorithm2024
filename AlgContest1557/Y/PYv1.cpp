//
// Created by wpan on 10/31/24.
//
#include<bits/stdc++.h>
using namespace std;

int n, m, mp[105][105];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool vis[105][105];

struct node {
    int x, y;
    int d;
} adress;

int bfs(int x, int y) {
    queue<node> q;
    q.push({x, y, 0});
    while (!q.empty()) {
        int cx = q.front().x, cy = q.front().y, d = q.front().d;
        q.pop();
        if (cx == n && cy == m) {
            return d;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m)continue;
            if (!vis[nx][ny] && mp[nx][ny] == 0) {
                vis[nx][ny] = 1;
                q.push({nx, ny, d + 1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)cin >> mp[i][j];
    int ans = bfs(1, 1);
    cout << ans << '\n';
    return 0;
}
