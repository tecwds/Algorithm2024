//
// Created by wpan on 10/15/24.
//
#include<bits/stdc++.h>
using namespace std;

int ans[10], c[10];

char nb[] = {'A', 'B', 'C', 'D', 'E'};// 根据输出格式的标记数组

int mmp[6][6] = {{0, 13, 11, 10, 4, 7},
                {0, 13, 10, 10, 8, 5},
                {0, 5, 9, 7, 7, 4},
                {0, 15, 12, 10, 11, 5},
                {0, 10, 11, 8, 8, 4}};

int sum = 0;

int res = 0;

bool vis[10];

void print(){
    for(int i = 0;i < 5;i ++){
        cout << nb[i] << ':' << 'J' << c[i] <<'\n';
    }
    cout << "supply:" << res << '\n';
}

void dfs(const int d){
    for(int j = 1;j <= 5;j ++){
        if(vis[j])continue;
        sum += mmp[d][j];
        vis[j] = true;
        ans[d] = j;
        if(d == 4){
            if(sum > res){
                res = sum;
                memcpy(c, ans, sizeof ans);
            }
        }else {
            dfs(d + 1);
        }
        vis[j] = false;
        sum -= mmp[d][j];
    }
}

int main(){
    memset(vis, 0, sizeof vis);
    dfs(0);
    print();
    return 0;
}