//
// Created by wpan on 12/5/24.
//
#include <iostream>
using namespace std;

int n;
int h;
int fi[30];
int di[30];
int ti[30];
int cfi[30];

struct lakeNode {
    int num[30];
    int maxn;
} lake[30];

int get_max(const int p[], const int i, const int j) {
    int c_max = p[i];
    int loc = i;

    for (int m = i + 1; m <= j; ++m) {
        if (p[m] > c_max) {
            c_max = p[m];
            loc = m;
        }
    }
    return loc;
}

void fishing() {
    const int tt = h * 60;

    // 初始化
    for (int i = 1; i <= n; ++i) {
        lake[i].maxn = 0;
        for (int j = 1; j <= n; ++j)
            lake[i].num[j] = 0;
    }

    // 枚举
    for (int i = 1; i <= n; ++i) {
        int ct = tt;
        int t = 0;
        for (int j = 0; j <= i; ++j) {
            cfi[j] = fi[j];
            ct = j < i ? ct - ti[j] * 5 : ct;
        }

        while (t < ct) {
            const int k = get_max(cfi, 1, i);
            lake[i].maxn += cfi[k];
            lake[i].num[k] += 5;

            cfi[k] >= di[k] ? cfi[k] -= di[k] : cfi[k] = 0;

            t += 5;
        }
    }

    for (int i = 1; i <= n; ++i) cfi[i] = lake[i].maxn;

    const int best = get_max(cfi, 1, n);

    for (int i = 1; i <= n; ++i) {
        i != n ? cout << lake[best].num[i] << ", " : cout << lake[best].num[i];
    }
    cout << "\nNumber of fish expected: " << lake[best].maxn << endl << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    while (cin >> n && n != 0) {
        cin >> h;

        for (int i = 1; i <= n; ++i) cin >> fi[i];
        for (int i = 1; i <= n; ++i) cin >> di[i];
        for (int i = 1; i < n; ++i) cin >> ti[i];

        fishing();
    }

    return 0;
}

