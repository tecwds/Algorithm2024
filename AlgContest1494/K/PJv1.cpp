//
// Created by wpan on 10/1/24.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    size_t n;
    cin >> n;

    vector<int> queue(n + 1);

    for (size_t i = 1; i <= n; ++i) {
        cin >> queue[i];
    }

    vector<int> prefix1(n + 1, 0);
    vector<int> prefix2(n + 1, 0);

    for (size_t i = 1; i <= n; ++i) {
        prefix1[i] = prefix1[i - 1] + (queue[i] == 1 ? 1 : 0);
        prefix2[i] = prefix2[i - 1] + (queue[i] == 2 ? 1 : 0);
    }

    size_t min_ = n;

    for (size_t i = 0; i <= n; ++i) {
        size_t changes = (i - prefix1[i]) + ((n - i) - (prefix2[n] - prefix2[i]));
        min_ = min(min_, changes);
    }

    size_t all_ones = n - prefix1[n];
    size_t all_twos = n - prefix2[n];

    min_ = min({min_, all_ones, all_twos});

    cout << min_ << endl;

    return 0;
}
