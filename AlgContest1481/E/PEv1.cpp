//问题 E: 交叉格子 
#include <iostream>

using namespace std;

// 网格
// max 100 * 100
// c[i][j]
char grid[111][111];

int h; // 行
int w; // 列

int result_k[105];

int check_grid(int x, int y, int len) {
    // 中心点 pos_x, pos_y (x, y)

    // 长度
    int len_ = 1;

    // 左上: i - 1, j - 1
    // 左下: i + 1, j - 1
    // 右上: i - 1, j + 1
    // 右下: i + 1, j + 1

    bool flag = false;

    while (
        grid[x - len_][y - len_] == '#' &&
        grid[x + len_][y - len_] == '#' &&
        grid[x - len_][y + len_] == '#' &&
        grid[x + len_][y + len_] == '#'
    ) {
        if (flag) {
            len_++;
        }
        flag = true;
    }
      
    return flag ? len_ : 0;
}




int main() {
    // 关掉缓存区
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 2; i <= h - 1; i++) {
        for (int j = 2; j <= w - 1; j++) {
            if (grid[i][j] == '#') {
                // cout << "i = " << i << " j = " << j <<
                // " check_grid " << check_grid(i, j, 1) << endl;
                result_k[check_grid(i, j, 1) - 1]++;
            }
        }
}

    for (int i = 1; i <= min(h, w); i++) {
        // for (int j = 0; j < result_k[i]; j++) {
            cout << result_k[i] << " ";
        // }
    }
    // result_k[check_grid()]

    return 0;
}