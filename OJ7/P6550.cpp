#include<bits/stdc++.h>
using namespace std;

enum { _n = 100007, INF = 1 << 30 };

int dfn[_n * 2], low[_n * 2], idx, H[_n], h;
int sz[_n * 2], son[_n * 2], top[_n * 2], I[_n * 2], F[_n * 2];
u32string G[_n], E[_n * 2];
int n, K, w[_n];
multiset<int> _S[_n], *S;

void tarj(int u) {
    H[++h] = u, dfn[u] = low[u] = ++idx;
    for (const int v: G[u])
        if (!dfn[v]) {
            tarj(v);
            if (dfn[u] <= low[v])
                for (E[u] += ++K; H[h + 1] != v; --h)
                    E[K] += H[h], S[K].insert(w[H[h]]);
            else low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], dfn[v]);
}

void dfs(const int u) {
    sz[u] = 1;
    for (const int v: E[u])
        dfs(v), F[v] = u, sz[u] += sz[v],
                sz[son[u]] > sz[v] ? : son[u] = v;
}

void dfs1(int u, int t) {
    dfn[u] = ++idx, I[idx] = u, top[u] = t;
    if (son[u]) dfs1(son[u], t);
    for (int v: E[u]) if (v != son[u]) dfs1(v, v);
}

int N, T[8 * _n];

void build(int k) {
    N = 1 << __lg(k + 1) + 1;
    for (int i = 1; i <= k; ++i)
        T[N + i] = I[i] > n ? *S[I[i]].begin() : w[I[i]];
    for (int i = N - 1; i; --i)
        T[i] = min(T[2 * i], T[2 * i | 1]);
}

void mod(int _x, int k) {
    int x = _x + N;
    for (T[x] = k; x >>= 1;)
        T[x] = min(T[2 * x], T[2 * x | 1]);
}

int query(int _l, int _r, int W = INF) {
    for (int l = _l + N - 1, r = _r + N + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
        l & 1 ? : W = min(W, T[l ^ 1]),
                ~r & 1 ? : W = min(W, T[r ^ 1]);
    return W;
}

int ask(int a, int b, int W = INF) {
    while (top[a] != top[b]) {
        if (dfn[top[a]] < dfn[top[b]]) swap(a, b);
        W = min(W, query(dfn[top[a]], dfn[a]));
        a = F[top[a]];
    }
    if (dfn[a] > dfn[b]) swap(a, b);
    W = min(W, query(dfn[a], dfn[b]));
    return min(W, a > n ? w[F[a]] : INF);
}

int main() {
    int m, q, a, b;
    char C;
    cin >> n >> m >> q, K = n, S = _S - n;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    while (m--) cin >> a >> b, G[a] += b, G[b] += a;
    tarj(1), dfs(1);
    idx = 0, dfs1(1, 1), build(K);
    while (q--) {
        cin >> C >> a >> b;
        if (C == 65) cout << ask(a, b) << '\n';
        else {
            if (a ^ 1) {
                S[F[a]].erase(S[F[a]].find(w[a]));
                S[F[a]].insert(b);
                mod(dfn[F[a]], *S[F[a]].begin());
            }
            w[a] = b, mod(dfn[a], b);
        }
    }
}
