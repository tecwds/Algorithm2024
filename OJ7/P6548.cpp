#include<bits/stdc++.h>
using namespace std;
int n, x[5];

void f(int y[]) {
    int j, cnt = 0;
    bool v[4] = {false, false, false, false};

    for (int i = 0; i < n; i++) {
        for (j = 0; j < 4; j++) {
            if (!v[j] && y[j] == x[i]) {
                v[j] = true;
                cnt++;
                break;
            }
        }
    }
    if (cnt == n) {
        puts("YES");
        for (j = 0; j < 4; j++)if (!v[j])cout << y[j] << endl;
        exit(0);
    }
}

int main() {
    int i;
    cin >> n;
    for (i = 0; i < n; i++)cin >> x[i];
    for (i = 1; i <= 500; i++) {
        for (int j = i; j <= 2 * i; j++) {
            int y[4] = {i, j, 4 * i - j, 3 * i};
            f(y);
        }
    }
    puts("NO");
}
