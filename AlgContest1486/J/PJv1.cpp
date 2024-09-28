//
// Created by wpan on 24-9-29.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int m;
    int k;

    cin >> n >> m >> k;

    // nm 矩阵（A）
    vector<vector<int>> nm(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> nm[i][j];
        }
    }

    // mk 矩阵（B）
    vector<vector<int>> mk(m, vector<int>(k));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> mk[i][j];
        }
    }

    // 结果矩阵
    vector<vector<int>> res(n, vector<int>(k, 0));

    // 计算
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int p = 0; p < m; ++p) {
                res[i][j] += nm[i][p] * mk[p][j];
            }
        }
    }

    // cout
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << res[i][j];
            if (j < k - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}