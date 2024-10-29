//
// Created by wpan on 10/29/24.
//
#include <iostream>
#include <queue>
using namespace std;

constexpr int N = 205;

int n;

int a[N];
int b[N];

queue<int> q;

// 广搜
void bfs() {
    while (!q.empty()) {
        int p = q.front();
        q.pop();

        if (p + a[p] <= n &&
            (!b[p + a[p]] || b[p + a[p]] > b[p] + 1)) {
            b[p + a[p]] = b[p] + 1;
            q.push(p + a[p]);
        }

        if (p - a[p] >= 1 &&
            (!b[p - a[p]] || b[p - a[p]] > b[p] + 1)) {
            b[p - a[p]] = b[p] + 1;
            q.push(p - a[p]);
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s;
    int e;

    cin >> n >> s >> e;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    if (s != e) {
        q.push(s);
        bfs();
        if (b[e] == 0) cout << -1;
        else cout << b[e];
    }
    else cout << 0;

    return 0;
}