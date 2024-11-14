//
// Created by wpan on 11/12/24.
//
#include <iostream>
#include <climits>
using namespace std;

constexpr int N = 55;

int mp[N][N];
int dis[N];
int v[N];

int n;
int s;

void dijkstra() {
    for (int i = 0; i < n; ++i) {
        dis[i] = INT_MAX;
        v[i] = 0;
    }
    dis[s] = 0;

    for (int j = 0; j < n; ++j) {
        int k = -1;

        for (int i = 0; i < n; ++i)
            if (!v[i] && (k == -1 || dis[i] < dis[k])) k = i;

        v[k] = 1;

        for (int i = 0; i < n; ++i)
            if (!v[i] && dis[k] + mp[k][i] < dis[i]) dis[i] = dis[k] + mp[k][i];
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> n >> s;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> mp[i][j];
            if (mp[i][j] == 0 && i != j) mp[i][j] = INT_MAX;
        }

    dijkstra();

    for (int i = 0; i < n; ++i) {
        if (i != s) {
            if (dis[i] < INT_MAX) cout << dis[i] << " ";
            else cout << -1 << endl;
        }
    }
    return 0;
}
