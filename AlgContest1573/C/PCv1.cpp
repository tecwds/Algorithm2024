//
// Created by wpan on 10/31/24.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    /// left
    int l;

    /// right
    int r;
} tv;

bool cmp(const tv a, const tv b) {
    return a.r < b.r;
}

int main() {
    vector<tv> vec;

    int n; // 节目个数
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        vec.clear();

        for (int si, ei, i = 0; i < n; ++i) {
            cin >> si >> ei;
            vec.push_back({si, ei});
        }

        sort(vec.begin(), vec.end(), cmp);

        int end_t = vec[0].r;
        int num = 1;

        for (int i = 1; i < n; ++i) {
            if (vec[i].l >= end_t) {
                end_t = vec[i].r;
                ++num;
            }
        }

        cout << num << endl;
    }
    return 0;
}
