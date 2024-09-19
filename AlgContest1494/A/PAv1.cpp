#include <iostream>

using namespace std;

// 座位总数
int n;

// 座位号
int k;

// 被绊倒的人数
int ans;

int main() {
    cin >> n >> k;

    if (n/2 >= k) {
        ans = n - k - 2;
    } else ans = k - 3;

    cout << ans << endl;

    return 0;
}