//
// Created by wpan on 11/14/24.
//
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct {
    int x;
    int y;
    int w;
} edge;

edge edges [200005];

int f [200005];
int n;
int k;
int m;
int ans;
int p = 1;

int find(const int k) {
    if (f[k] == k) return k;
    return f[k] = find(f[k]);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        f[i] = i;
        for (int j = 1; j <= n; ++j) {
            cin >> k;
            if (j > i && k != 0) {
                m++;
                edges[m].x = i;
                edges[m].y = j;
                edges[m].w = k;
            }
        }
    }

    std::sort(edges + 1, edges + m + 1, [](const edge a, const edge b) { return a.w < b.w; });

    for (int i = 1; i <=m; ++i) {
        if (find(edges[i].x) != find(edges[i].y)) {
            ans = edges[i].w;
            f[find(edges[i].x)] = edges[i].y;
            p++;

            // 已经找到最小生成树了
            if (p == n) break;
        }
    }

    cout << ans<< endl;

    return 0;
}
