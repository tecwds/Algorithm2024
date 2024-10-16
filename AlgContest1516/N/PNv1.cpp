//
// Created by wpan on 10/16/24.
//

#include <iostream>
using namespace std;

const long long MAX = 30; // 定义棋盘的最大尺寸

long long dp[MAX][MAX]; // 动态规划数组
long long n, m, x, y; // B点的坐标(n, m)和马的坐标(x, y)

// 马可以控制的点的坐标
long long horseX[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
long long horseY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {
    // 读取输入
    cin >> n >> m >> x >> y;

    // 初始化动态规划数组
    for (long long i = 0; i < MAX; ++i) {
        for (long long j = 0; j < MAX; ++j) {
            dp[i][j] = 0; // 默认路径数为0
        }
    }

    // 标记马的控制点
    for (long long i = 0; i < 8; ++i) {
        long long nextX = x + horseX[i];
        long long nextY = y + horseY[i];
        if (nextX >= 0 && nextX < MAX && nextY >= 0 && nextY < MAX) {
            dp[nextX][nextY] = -1; // 标记为不可达
        }
    }

    // 马的当前位置也是不可达的
    dp[x][y] = -1;

    // 初始化起点
    dp[0][0] = 1;

    // 动态规划填充数组
    for (long long i = 0; i <= n; ++i) {
        for (long long j = 0; j <= m; ++j) {
            if (dp[i][j] == -1) continue; // 如果是马的控制点，则跳过
            if (i == 0 && j == 0) continue; // 起点已经初始化

            // 从上方和左方累加路径数
            if (i > 0 && dp[i-1][j] != -1) {
                dp[i][j] += dp[i-1][j]; // 从上方来
            }
            if (j > 0 && dp[i][j-1] != -1) {
                dp[i][j] += dp[i][j-1]; // 从左边来
            }
        }
    }

    // 输出结果
    cout << dp[n][m] << endl;

    return 0;
}
