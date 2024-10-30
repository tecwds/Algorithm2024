//
// Created by wpan on 10/30/24.
//
#include <bits/stdc++.h>
using namespace std;

int n, m, k, bcnt, ans;
int b[51][51];
int del[51], q[105], fa[51], vis[51], d[51];
bool flag, cho;

void read(int &res) {
    res = 0;
    int pd = 1;
    char a = getchar();
    while (a < '0' || a > '9') {
        if (a == '-') pd = -pd;
        a = getchar();
    }
    while (a >= '0' && a <= '9') {
        res = (res << 1) + (res << 3) + (a - '0');
        a = getchar();
    }
    res *= pd;
}

void spfa() {
    int l = 1, r = 1;
    memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    q[1] = 1;
    d[1] = 0;
    vis[1] = 1;

    while (l <= r) {
        int cur = q[l++];
        vis[cur] = 0;
        for (int i = 1; i <= n; ++i) {
            if (b[cur][i] > 0 && !del[i] && d[i] > d[cur] + 1) {
                d[i] = d[cur] + 1;
                fa[i] = cur;
                if (!vis[i]) {
                    vis[i] = 1;
                    q[++r] = i;
                }
            }
        }
    }
}

void find(int depth) {
    if (depth > ans) return;

    spfa();
    if (d[n] > k) {
        ans = min(ans, depth);
        return;
    }

    int chosen[51], cnt = 0, tem = n;
    while (tem) {
        if (tem != 1 && tem != n) chosen[++cnt] = tem;
        tem = fa[tem];
    }

    for (int i = 1; i <= cnt; ++i) {
        del[chosen[i]] = 1;
        find(depth + 1);
        del[chosen[i]] = 0;
    }
}

int main() {
    read(n);
    read(m);
    read(k);
    int x, y;

    for (int i = 1; i <= m; ++i) {
        read(x);
        read(y);
        b[x][y] = 1;
    }

    fa[1] = 0;
    ans = INT_MAX;
    find(0);
    printf("%d\n", ans);

    return 0;
}