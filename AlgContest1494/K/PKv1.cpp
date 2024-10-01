//
// Created by wpan on 10/1/24.
//
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

// 定义每个移动如何影响时钟
const array<vector<int>, 9> moves = {
    {
        {0, 1, 3, 4},
        {0, 1, 2},
        {1, 2, 4, 5},
        {0, 3, 6},
        {1, 3, 4, 5, 7},
        {2, 5, 8},
        {3, 4, 6, 7},
        {6, 7, 8},
        {4, 5, 7, 8}
    }
};

// 应用一个操作
void apply_move(vector<int> &clock,
                const int move,
                const int times) {
    for (const auto i: moves[move])
        clock[i] = (clock[i] + times) % 4;
}

// 递归搜索
void dfs(vector<int> &clock,
         vector<int> &step_solution,
         vector<int> &best_solution,
         const int move_idx) {
    if (move_idx == 9) {
        if (all_of(clock.begin(), clock.end(), [](const int c) { return c == 0; }) &&
            (best_solution.empty() || step_solution.size() < best_solution.size()))
            // if block
            best_solution = step_solution;

        return;
    }

    for (int i = 0; i < 4; ++i) {
        step_solution.insert(step_solution.end(), i, move_idx + 1);
        apply_move(clock, move_idx, i);

        dfs(clock, step_solution, best_solution, move_idx + 1);
        apply_move(clock, move_idx, (4 - i) % 4); // 还原状态

        step_solution.resize(step_solution.size() - i);
    }
}

int main() {
    vector<int> initial_state(9);

    for (size_t i = 0; i < 9; ++i) {
        cin >> initial_state[i];
    }

    vector<int> solution;
    vector<int> best_solution;

    dfs(initial_state, solution, best_solution, 0);

    for (const auto& move: best_solution) {
        cout << move;
    }

    cout << endl;

    return 0;
}
