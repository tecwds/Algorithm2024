#include <iostream>
using namespace std;
int G[50][51], n, m, t, i, j, k, a, b, ans, s;

int main() {
    cin >> n >> m;
    for (i = 0; i < n; i++) for (j = 1; j <= m; j++)cin >> G[i][j], G[i][j] += G[i][j - 1];
    cin >> a >> b;
    for (ans = n * m, t = 0; t < 2; t++) {
        for (i = 0; i <= n - a; i++)
            for (j = 0; j <= m - b; j++) {
                for (s = k = 0; k < a; k++) s += G[i + k][j + b] - G[i + k][j];
                ans = min(ans, s);
            }
        s = a;
        a = b;
        b = s;
    }
    cout << ans << endl;
    return 0;
}
