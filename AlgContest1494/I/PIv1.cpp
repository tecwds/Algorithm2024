//
// Created by wpan on 10/1/24.
//
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

constexpr int N = 4;
// 棋盘
vector<string> board(N);

// 翻转棋子及其周围的棋子颜色
void reverse(const int x, const int y) {
    vector<pair<int, int> > direct = {
        {-1, 0}, {1, 0},
        {0, -1}, {0, 1}
    };

    for (const auto &[dx, dy]: direct)
        if (const int nx = x + dx, ny = y + dy;
            nx >= 0 && nx < N && ny >= 0 && ny < N)
                board[nx][ny] = (board[nx][ny] == 'b') ? 'w' : 'b';
    board[x][y] = (board[x][y] == 'b') ? 'w' : 'b';
}

// 纯色检查
bool check_uniform() {
    char color = board[0][0];
    return all_of(board.begin(), board.end(), [&color](const string& str) {
        return all_of(str.begin(), str.end(), [&color](const char& ch) {
            return ch == color;
        });
    });
}

// 枚举所有可能的翻转组合
int solve() {
    int min_flips = INT_MAX;

    for (int mask = 0; mask < (1 << (N * N)); ++mask) {
        vector<string> temp_board = board;
        int flips = 0;

        for (int i = 0; i < N * N; ++i)
            if (mask & (1 << i)) {
                const int x = i / N;
                const int y = i % N;
                reverse(x, y);
                ++flips;
            }
        if (check_uniform())
            min_flips = min(min_flips, flips);

        // 恢复初始状态
        board = temp_board;
    }
    return min_flips == INT_MAX ? -1 : min_flips;
}

int main() {
    for (size_t i = 0; i < N; ++i) {
        cin >> board[i];
    }

    if (const int flips = solve(); -1 == flips)
        cout << "Impossible" << endl;
    else
        cout << flips << endl;

    return 0;
}
