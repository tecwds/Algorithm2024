#include <iostream>
using namespace std;

int sum;
int n;
int m;
int ans;

int c(int m, int n) {
    long long s;
    int p1, p2;

    if (n == 0) {
        return 1;
    }

    s = 1;
    p1 = 2;

    for (p2 = m; p2 >= m - n + 1; p2--){
        s *= p2;
        if (s % p1 == 0 && p1 <= n) {
            s /= p1;
            p1++;
        }
    }
    return s;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i <= m; i++) {
        int j = m - i;
        if (abs(j - i) % n == 0) ans += c(m, i);
    }
    cout << ans << endl;
    return 0;
}