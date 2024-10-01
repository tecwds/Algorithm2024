//
// Created by wpan on 10/1/24.
//
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

using Cows = pair<char, int>;

bool compare(
    const Cows &a,
    const Cows &b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;

    vector<Cows> cows(n);
    vector<int> position;

    for (size_t i = 0; i < n; ++i) {
        cin >> cows[i].first >> cows[i].second;
        position.push_back(cows[i].second);
    }

    sort(position.begin(), position.end());

    int min_lying = n;

    for (size_t i = 0; i < n; ++i) {
        int current_pos = position[i];
        int lie_count = 0;

        for (size_t j = 0; j < n; ++j)
            if ((cows[j].first == 'L' && cows[j].second < current_pos) ||
                (cows[j].first == 'G' && cows[j].second > current_pos))
                lie_count++;
        min_lying = min(min_lying, lie_count);
    }
    cout << min_lying << endl;

    return 0;
}
