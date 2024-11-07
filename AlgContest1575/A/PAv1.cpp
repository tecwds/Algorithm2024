//
// Created by wpan on 11/7/24.
//
#include <iostream>
using namespace std;

constexpr int N = 105;

int n;
int m;
int cnt;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char mp[N][N];
bool vis[N][N];

void dfs(const int sx, const int sy) {
    for (int i = 0; i < 4; ++i) {
        // const int x = sx + dx[i];
        if (const int x = sx + dx[i], y = sy + dy[i];
            x >= 1 && x <= n && y >= 1 && y <= n && mp[x][y] != '0' && !vis[x][y]) {
            vis[x][y] = true;
            dfs(x, y);
        }
    }
}

int main(int argc, char *argv[]) {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; i <= n; ++j)
            cin >> mp[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (mp[i][j] != '0' && !vis[i][j]) {
                vis[i][j] = true;
                dfs(i, j);
                cnt++;
            }

    cout << cnt << endl;

    return 0;
}
