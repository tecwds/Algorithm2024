//
// Created by wpan on 10/30/24.
//
#include<bits/stdc++.h>
using namespace std;

bool mp[6][6];
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int ans;
int d;

void dfs(const int x, const int y) {
    for (int k = 0; k < 8; k++) {
        const int nx = x + dx[k];
        const int ny = y + dy[k];

        if (nx > 5 ||
            ny > 5 ||
            nx < 1 ||
            ny < 1) continue;

        if (!mp[nx][ny]) {
            mp[nx][ny] = true;
            d++;

            if (d == 24) ans++;
            else dfs(nx, ny);

            d--;
            mp[nx][ny] = false;
        }
    }
}


int main() {
    mp[1][1] = true;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}
