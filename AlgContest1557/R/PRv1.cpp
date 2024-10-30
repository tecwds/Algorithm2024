//
// Created by wpan on 10/31/24.
//
#include<stdio.h>
#include<queue>
#include<iostream>
#include<string.h>
using namespace std;
int m, n;
char mp[105][105];

void dfs(int a, int b) {
    mp[a][b] = '*'; //找到了油田就把它改成*避免重复查找
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = a + dx;
            int ny = b + dy;
            if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && mp[nx][ny] == '@')
                dfs(nx, ny); //最关键的地方，递归找到的新油田。
        }
    }
}

int main() {
    while (cin >> m >> n && m && n) //这里当m和m为0的时候就退出循环
    {
        int sum = 0; //每次初始化sum为0。
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> mp[i][j];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (mp[i][j] == '@') {
                    dfs(i, j);
                    sum++; //每找到一个油藏sum就++。
                }
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
