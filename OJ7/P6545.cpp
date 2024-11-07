#include<bits/stdc++.h>
using namespace std;
constexpr int MAX = 3009;
int n, m, k, be[MAX][MAX];
vector<int> g[MAX];
long long ans = 0;

int main() {
    cin >> n >> m;
    for (int i = 0, v, u; i < m; i++)cin >> v >> u, v--, u--, g[v].push_back(u);
    for (int i = 0; i < n; i++)
        for (const auto j: g[i])
            for (const auto k: g[j])
                if (i != k) ans += be[i][k], be[i][k]++;
    cout << ans;

    return 0;
}
