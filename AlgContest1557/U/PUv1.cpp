//
// Created by wpan on 10/31/24.
//
#include<bits/stdc++.h>
using namespace std;

int n, m;
int cnt = 0;

int num[1008];
bool vis[1008];

vector<int> g[1008];
vector<int> p[1008];

void rfs(int k) {
    for (int i: g[k]) {
        if (!vis[i]) {
            vis[i] = true;
            p[cnt].push_back(i);
            rfs(i);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> num[i];
    for (int j = 1; j <= m; j++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            p[++cnt].push_back(i);
            rfs(i);
        }
    }
    int mx_pos = -1;
    int pos_mx = -1;
    int mx_num = -1;
    int pos_num = -1;
    for (int i = 1; i <= cnt; i++) {
        int t = 0;
        int b = 0;
        for (int j: p[i]) {
            b += num[j];
            t++;
        }
        if (t > mx_pos) {
            mx_pos = t;
            pos_mx = i;
        }
        if (b > mx_num) {
            mx_num = b;
            pos_num = i;
        }
    }
    sort(p[pos_mx].begin(), p[pos_mx].end());
    for (int x: p[pos_mx]) {
        cout << x << ' ';
    }
    cout << '\n';
    sort(p[pos_num].begin(), p[pos_num].end());
    for (int x: p[pos_num]) {
        cout << x << ' ';
    }
    return 0;
}
