//
// Created by wpan on 10/30/24.
//
#include<bits/stdc++.h>
using namespace std;

char c1, c2;

int a1, a2, ans, dx[] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[] = {2, 1, -1, -2, -2, -1, 1, 2}, res, b1, b2;

bool mp[10][10];

void dfs(int x, int y) {
    if (res > ans)return;
    if (x == a2 && y == b2) {
        ans = min(res, ans);
        return;
    }
    //	cout << ans << '\n';
    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 1 || ny < 1 || nx > 8 || ny > 8)continue;
        if (!mp[nx][ny]) {
            mp[nx][ny] = 1;
            res++;
            dfs(nx, ny);
            res--;
            mp[nx][ny] = 0;
        }
    }
}

int main() {
    while (cin >> c1 >> a1 >> c2 >> a2) {
        memset(mp, 0, sizeof mp);
        ans = 1e9;
        res = 0;
        b1 = c1 - 'a' + 1;
        b2 = c2 - 'a' + 1;
        //		cout << b2 << '\n';
        //		cout << b1 << '\n';
        //		mp[a1][b1] = 1;
        dfs(a1, b1);
        //		cout << ans << '\n';
        cout << "To get from " << c1 << a1 << " to " << c2 << a2 << " takes " << ans << " knight moves.\n";
    }
    return 0;
}
