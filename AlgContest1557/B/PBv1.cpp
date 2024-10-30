//
// Created by wpan on 10/15/24.
//
#include <bits/stdc++.h>
using namespace std;

int aa[9];
int bb[9];

int dir[4][2] = {2, 1, 1, 2, -1, 2, -2, 1};

int min_jmps = INT_MAX;

vector<pair<int, int>> best;

bool in_map(const int x, const int y) {
    return x >= 0 && x <= 4 && y >= 0 && y <= 8;
}


void output() {
    cout << "0,0";
    for (const auto &[fst, snd] : best) {
        cout << "->" << fst << "," << snd;
    }
    cout << endl;
}


void dfs(const int id, const int jmps, vector<pair<int, int>> path) {
    const int x1 = aa[id];
    const int y1 = bb[id];

    if (y1 == 8) {
        if (x1 == 4) {
            if (jmps < min_jmps) {
                min_jmps = jmps;
                best = path;
            }
        }
        return;
    }

    if (jmps >= min_jmps) return;

    for (const auto & i : dir) {
        const int x2 = x1 + i[0];
        const int y2 = y1 + i[1];
        if (in_map(x2, y2)) {
            aa[id + 1] = x2;
            bb[id + 1] = y2;
            path.emplace_back(x2, y2);
            dfs(id + 1, jmps + 1, path);
            path.pop_back();
        }
    }
}

int main() {
    dfs(0, 0, best); // 从(0,0)开始扩展状态
    output();
    return 0;
}

