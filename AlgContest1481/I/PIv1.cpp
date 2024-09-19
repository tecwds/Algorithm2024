#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

// 无穷大
#define Inf 0x3f3f3f

using namespace std;

int t;
int res;
bool mtx[10][10];
bool blk[10][10];


int check(int cnt){
    int sum=cnt;

    // 复制,留一个备份
    std::memcpy(blk, mtx, sizeof(mtx));
    
    // 遍历第一行，检查是否有未亮的灯泡
    for(int i=1;i<=4;i++) {
        for(int j=1;j<=5;j++) {
            if(!blk[i][j]) {
                sum++;
                blk[i][j]=!blk[i][j];
                blk[i+1][j]=!blk[i+1][j];
                blk[i+1][j-1]=!blk[i+1][j-1];
                blk[i+1][j+1]=!blk[i+1][j+1];
                blk[i+2][j]=!blk[i+2][j];
            }
        }
 
    }
    for(int i=1;i<=5;i++)
        if(!blk[5][i])return Inf;
 
    return sum;
 
 
}
int dfs(int cnt,int k) {
    if(cnt > 5) {
        res = min(res, check(k));
        return 0;
    }
    mtx[1][cnt]=!mtx[1][cnt];
    mtx[1][cnt-1]=!mtx[1][cnt-1];
    mtx[1][cnt+1]=!mtx[1][cnt+1];
    mtx[2][cnt]=!mtx[2][cnt];
 
    dfs(cnt+1,k+1);//按下这个开关
 
    mtx[1][cnt]=!mtx[1][cnt];
    mtx[1][cnt-1]=!mtx[1][cnt-1];
    mtx[1][cnt+1]=!mtx[1][cnt+1];
    mtx[2][cnt]=!mtx[2][cnt];
 
    dfs(cnt+1,k);//不按下这个开关
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;

    while(t--) {
        for(int i = 1; i <= 5; i++)
            for(int j = 1; j <= 5; j++)
                scanf("%1d", &mtx[i][j]);

        res = Inf;
        dfs(1, 0);
 
        if(res < 7) cout << res << endl;
        else cout << "-1" << endl;
    }
 
    return 0;
}