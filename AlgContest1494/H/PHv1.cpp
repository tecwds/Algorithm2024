//
// Created by wpan on 10/1/24.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;

    // 构建双平方数集合
    const int max_val = m * m * 2;

    vector<bool> aa(max_val + 1, false);
    vector<int> kk;

    for (int p = 0; p <= m; ++p) {
        for (int q = 0; q <= m; ++q) {
            int bisquare = p * p + q * q;
            if (!aa[bisquare]) {
                aa[bisquare] = true;
                kk.push_back(bisquare);
            }
        }
    }

    sort(kk.begin(), kk.end());

    vector<pair<int, int>> results;

    // 枚举所有可能的起始数 a 和公差 b
    for (size_t i = 0; i < kk.size(); ++i) {
        for (size_t j = i + 1; j < kk.size(); ++j) {
            int a = kk[i];
            int b = kk[j] - kk[i];

            int cnt = 1;
            int current = a;
            while (cnt < n) {
                current += b;
                if (current > max_val || !aa[current]) {
                    break;
                }
                cnt++;
            }

            if (cnt == n) {
                results.emplace_back(a, b);
            }
        }
    }

    // 按 b 和 a 排序
    sort(results.begin(), results.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    });

    if (results.empty()) {
        cout << "NONE" << endl;
    } else {
        for (const auto& res : results) {
            cout << res.first << " " << res.second << endl;
        }
    }

    return 0;
}
