#include <iostream>

using namespace std;

int n;
int k;

// 分法总数
int ans;

/**
 * @param x     当前这堆分的数字
 * @param kk    当前是第几份
 * @param nn    还剩多少数字为分
 */
void solve(int x, int kk, int nn) {
    if (kk == k) {
        ans++;
        // return;
    } else {
        for (int i = x; i <= nn / (k + 1 - kk); i++) {
            solve(i, kk + 1, nn - i);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    solve(1, 1, n);

    cout << ans << endl;

    return 0;
}