//
// Created by wpan on 10/31/24.
//
#include <algorithm>
#include <iostream>
#include <variant>
#include <vector>
using namespace std;

typedef struct {
    int wi;
    int ci;
} bk;

// 高价值
bool high_level(const bk a, const bk b) {
    return (1.0 * a.wi / a.ci) > (1.0 * b.wi / b.ci);
}

int main() {
    vector<bk> back;

    int v;
    int n;
    int res = 0;

    cin >> v >> n;

    int w;
    int c;
    for (int i = 0; i < n; ++i) {
        cin >> w >> c;
        back.push_back({w, c});
    }

    sort(back.begin(), back.end(), high_level);

    for (const auto [wi, ci] : back) {
        if (v >= ci) {
            res += wi;
            v -= ci;
        }
    }

    cout << res << endl;

    return 0;
}
