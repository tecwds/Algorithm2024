//
// Created by wpan on 11/14/24.
//
#include <iostream>
using namespace std;

constexpr int N = 20020;

int father[N];

int n;
int m;
int cnt;

int find(int);

void union_(const int x, const int y) {
    father[find(y)] = find(x);
}

int find(const int x) {
    if (father[x] != x) father[x] = find(father[x]);
    return father[x];
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) father[i] = i;

    int x;
    int y;

    while (m--) {
        cin >> x >> y;
        union_(x, y);
    }

    cin >> cnt;

    while (cnt--) {
        cin >> x >> y;
        if (find(x) == find(y)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
