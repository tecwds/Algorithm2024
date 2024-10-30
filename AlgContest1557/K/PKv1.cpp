//
// Created by wpan on 10/30/24.
//
#include <iostream>

using namespace std;
int n, m, cnt;
char m1[1008][1008];
bool v[1008][1008];
int m2[1008][1008];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void dfs(int x, int y) {
    m2[x][y] = cnt;
    v[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if (m1[nx][ny] == '.' && !v[nx][ny])dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)cin >> m1[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (m1[i][j] == '.' && !v[i][j]) {
                cnt++;
                dfs(i, j);
            }
    cout << cnt << '\n';
    return 0;
}



