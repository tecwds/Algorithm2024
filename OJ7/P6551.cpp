#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
constexpr int N = 114514, M = 333;
char s[N][19], c[114];
int n, m, q, x, y, tx[N][19], ty[N][19];

void upd(const int l, const int r) {
    rep(i, l, r)
        rep(j, 1, m)tx[i][j] = ty[i][j] = -1;
    rep(i, 1, m)if (s[l][i] == '^')tx[l][i] = l - 1, ty[l][i] = i;
    rep(i, l, r)tx[i][0] = tx[i][m + 1] = i, ty[i][0] = 0, ty[i][m + 1] = m + 1;
    rep(i, l, r) {
        rep(j, 1, m)
            if (i != l && s[i][j] == '^')tx[i][j] = tx[i - 1][j], ty[i][j] = ty[i - 1][j];
            else if (s[i][j] == '<')tx[i][j] = tx[i][j - 1], ty[i][j] = ty[i][j - 1];
        per(j, m, 1)if (s[i][j] == '>')tx[i][j] = tx[i][j + 1], ty[i][j] = ty[i][j + 1];
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    rep(i, 1, n)scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i += M)upd(i, min(n, i + M - 1));
    rep(i, 1, q) {
        scanf("%s%d%d", c, &x, &y);
        if (c[0] == 'C') {
            scanf("%s", c);
            s[x][y] = c[0];
            upd((x - 1) / M * M + 1, min(n, ((x - 1) / M + 1) * M));
        } else {
            int s;
            while (x > 0 && y > 0 && y <= m)s = x, x = tx[s][y], y = ty[s][y];
            printf("%d %d\n", x, y);
        }
    }
}
