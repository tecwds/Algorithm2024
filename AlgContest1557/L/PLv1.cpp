//
// Created by wpan on 10/30/24.
//
#include<bits/stdc++.h>
using namespace std;

char mp[1008][1008];

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int cnt, vis[1008][1008],n,m;

bool is(char x){
    int y = x - '0';
    return y ? 1 : 0;
}

void dfs(int x, int y){
    vis[x][y] = cnt;
    for(int k = 0;k < 4;k ++){
        int nx = x + dx[k], ny = y + dy[k];
        if(nx < 1 || ny < 1 || nx > n || ny > m)continue;
        if(is(mp[nx][ny]) && !vis[nx][ny])dfs(nx, ny);
    }
}


int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)cin >> mp[i][j];
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++){
            if(is(mp[i][j]) && !vis[i][j]){
                cnt ++;
                dfs(i, j);
            }
        }
    cout << cnt << '\n';
    return 0;
}