//
// Created by wpan on 10/31/24.
//
#include<bits/stdc++.h>
using namespace std;

string s;

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

string ps = "123804765";

struct node {
    string cs;
    int pos;
    int d;
};

int bfs(string s) {
    queue<node> q;
    int cpos = s.find('0');
    q.push({s, cpos, 0});
    set<string> vis;
    vis.insert(s);

    while (!q.empty()) {
        node cnode = q.front();
        q.pop();
        if (cnode.cs == ps) {
            return cnode.d;
        }
        int cx = cnode.pos / 3, cy = cnode.pos % 3;
        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k], ny = cy + dy[k];
            if (nx < 0 || ny < 0 || nx > 2 || ny > 2)continue;

            int npos = nx * 3 + ny;
            string ns = cnode.cs;
            swap(ns[cnode.pos], ns[npos]);
            if (!vis.count(ns)) {
                vis.insert(ns);
                q.push({ns, npos, cnode.d + 1});
            }
        }
    }
}


int main() {
    cin >> s;
    cout << bfs(s) << '\n';
    return 0;
}
