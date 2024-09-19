#include <iostream>

using namespace std;

int n;

// 10
int a;

// 5
int b;

// 2
int c;

// 1
int d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (a = 1; a <= n; a++) {
        for (b = 1; b <= n; b++) {
            for (c = 1; c <= n; c++) {
                for (d = 1; d <= n; d++) {
                    if (a * 10 + b * 5 + c * 2 + d == 100 &&
                        a + b + c + d == n
                    ) {
                        cout
                         << a << " "
                         << b << " "
                         << c << " "
                         << d << endl;
                    }
                }
            }
        }
    }

    return 0;
}