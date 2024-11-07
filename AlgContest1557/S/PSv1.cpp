//
// Created by wpan on 10/31/24.
//
/* HDU1253 胜利大逃亡 */

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int DIRECTSIZE = 6;

struct direct {
    int dx;
    int dy;
    int dz;
} direct[DIRECTSIZE] =
        {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};

const int MAXN = 50;
int cube[MAXN + 2][MAXN + 2][MAXN + 2];

struct node {
    int x, y, z, level;
};

int L, R, C, limit;
node start;

int bfs() {
    queue<node> q;

    start.x = 1;
    start.y = 1;
    start.z = 1;
    start.level = 0;
    q.push(start);

    cube[1][1][1] = 0;

    while (!q.empty()) {
        node front = q.front();
        q.pop();

        for (int i = 0; i < DIRECTSIZE; i++) {
            int nextx, nexty, nextz;

            nextx = front.x + direct[i].dx;
            nexty = front.y + direct[i].dy;
            nextz = front.z + direct[i].dz;

            if (cube[nextx][nexty][nextz]) {
                if (nextx == L && nexty == R && nextz == C)
                    return front.level + 1;

                if (front.level < limit) {
                    cube[nextx][nexty][nextz] = 0;

                    node v;
                    v.x = nextx;
                    v.y = nexty;
                    v.z = nextz;
                    v.level = front.level + 1;
                    q.push(v);
                }
            }
        }
    }

    return -1;
}

int main() {
    int t, ans, i, j, k;

    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &L, &R, &C, &limit);

        memset(cube, 0, sizeof(cube));

        for (i = 1; i <= L; i++)
            for (j = 1; j <= R; j++)
                for (k = 1; k <= C; k++) {
                    scanf("%d", &cube[i][j][k]);
                    cube[i][j][k] = 1 - cube[i][j][k];
                }

        ans = bfs();

        printf("%d\n", ans);
    }

    return 0;
}
