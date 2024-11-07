#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int b[111] = {0}, g[111] = {0}, n, i, r, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> j;
        b[j]++;
    }
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> j;
        g[j]++;
    }

    for (i = 1, r = 0; i < 101; i++) {
        while (g[i - 1] && b[i]) {
            r++;
            b[i]--;
            g[i - 1]--;
        }
        while (g[i] && b[i]) {
            r++;
            b[i]--;
            g[i]--;
        }
        while (g[i + 1] && b[i]) {
            r++;
            b[i]--;
            g[i + 1]--;
        }
    }

    printf("%d", r);

    return 0;
}
