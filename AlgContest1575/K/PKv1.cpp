//
// Created by wpan on 11/12/24.
//
#include <iostream>
using namespace std;

int n;
int v;
int mp[90][90];
int w;


int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> v;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            string s;
            cin >> s;
            if (s == "-") mp[i][j] = 0x7ffffff;
            else mp[i][j] = stoi(s);
        }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);

    for (int i = 1; i <= n; ++i) {
        if (i != v)
            cout << "(" << v << " -> " << i << ") = " << mp[v][i] << endl;
    }
    return 0;
}
