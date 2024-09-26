#include <iostream>
using namespace std;

int a[1001];

bool check(int n, int m) {
    if (n == 0) return false;
    if (a[n] == m) return true;
    if (check(n - 1, m - a[n])) return true;
    if (check(n - 1, m)) return true;
    return false;
}

int main() {
    int n;
    int m;

    cin >> n >> m;

    for (int j = 1; j <= n; j++) {
        cin >> a[j];
    }

    if (check(n, m)) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}