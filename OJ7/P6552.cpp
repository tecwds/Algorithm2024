#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
int ar[N], dp[N], n, s, l;
multiset<int> st, pt;

int main() {
    cin >> n >> s >> l;
    for (int i = 1; i <= n; ++i)cin >> ar[i];
    for (int i = 1, j = 1; i <= n; ++i) {
        st.insert(ar[i]);
        for (; *st.rbegin() - *st.begin() > s; ++j) {
            st.erase(st.find(ar[j]));
            if (i - j >= l)pt.erase(pt.find(dp[j - 1]));
        }
        if (i - j + 1 >= l)pt.insert(dp[i - l]);
        if (pt.begin() == pt.end())dp[i] = N;
        else dp[i] = *pt.begin() + 1;
    }
    int ret = dp[n] >= N ? -1 : dp[n];
    cout << ret << endl;
}
