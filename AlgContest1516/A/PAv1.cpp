#include <iostream>
using namespace std;

int main() {

    int n;

    while (~scanf("%d", &n)) {
        if (n <= 1) {
            cout << n << endl;
            // return 0;
            continue;
        } else if (n == 2) {
            cout << 1 << endl;
            // return 0;
            continue;
        }

        int f1 = 1;
        int f2 = 1;
        int fn = 0;

        for (int i = 3; i <= n; i++) {
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }

        cout << fn << endl;
    }
    return 0;
}