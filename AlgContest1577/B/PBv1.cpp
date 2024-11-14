//
// Created by wpan on 11/14/24.
//
#include <iostream>
using namespace std;

constexpr int N = 205;

typedef struct {
    int x;
    int y;
} Point;

Point mp[N][N];
Point k1;
Point k2;

Point find(const Point k) {
    if (mp[k.x][k.y].x == k.x && mp[k.x][k.y].y == k.y) return k;
    return mp[k.x][k.y] = find(mp[k.x][k.y]);
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    int m;
    int x;
    int y;
    char d;

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            mp[i][j].x = i;
            mp[i][j].y = j;
        }

    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> d;
        if (d == 'D') {
            k1 = find(mp[x][y]);
            k2 = find(mp[x + 1][y]);
        }
        else if (d == 'R') {
            k1 = find(mp[x][y]);
            k2 = find(mp[x][y + 1]);
        }

        if (k1.x == k2.x && k1.y == k2.y) {
            cout << i << endl;
            return 0;
        }
        mp[k1.x][k1.y] = k2;
    }

    cout << "draw" << endl;
    return 0;
}

