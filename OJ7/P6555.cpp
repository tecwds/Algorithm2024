#include<bits/stdc++.h>
using namespace std;
long long D, N, V[100005], X, a, b, i, M = 1e9 + 7;
vector<int> E[100005];

long long dfs(int n, int p, int m, int r) {
    long long x = 1;
    for (int v: E[n])if (v != p && V[v] - m <= D && (V[v] > m || (V[v] == m && v > r)))
        x = (x * (dfs(v, n, m, r) + 1)) % M;
    return x;
}

int main() {
    cin >> D >> N;
    for (i = 1; i <= N; i++)cin >> V[i];
    for (i = 1; i < N; i++)cin >> a >> b, E[a].push_back(b), E[b].push_back(a);
    for (i = 1; i <= N; i++)X = (X + dfs(i, -1, V[i], i)) % M;
    cout << X;

    return 0;
}
