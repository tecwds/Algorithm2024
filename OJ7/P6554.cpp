#include<cstdio>
#include<cstring>
#include <iostream>
#include<algorithm>
#define x 100003
#define r(i,n) for(int i=1;i<=n;i++)
using namespace std;
int a[x], d[x], e[x], g[x], z[x], c[x];

int main() {
    int n;
    cin >> n;
    r(i, n) cin >> a[i];
    memset(g, 127, sizeof(g));
    int ml = 0;
    r(i, n) {
        const int k = lower_bound(g + 1, g + n + 1, a[i]) - g;
        d[i] = k;
        g[k] = a[i];
        ml = max(ml, d[i]);
    }
    for (int i = n; i >= 1; i--) {
        const int k = lower_bound(g + 1, g + n + 1, -a[i]) - g;
        e[i] = k;
        g[k] = -a[i];
    }
    memset(c, 0, sizeof(c));
    r(i, n)
        if (d[i] + e[i] != ml + 1)z[i] = 1;
        else z[i] = 0, c[d[i]]++;
    r(i, n)if (!z[i])z[i] = c[d[i]] > 1 ? 2 : 3;
    r(i, n)printf("%d", z[i]);
}
