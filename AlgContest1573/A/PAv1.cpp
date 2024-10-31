//
// Created by wpan on 10/31/24.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int cmp(const int a, const int b) {
    return a < b;
}

int main() {
    vector<int> vec;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        vec.emplace_back(tmp);
    }

    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < n; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}