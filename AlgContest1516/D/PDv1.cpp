#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        long long f1 = 1;
        long long f2 = 3;
        long long fn = 0;

        if (tmp == 1) {
            cout << 1 << endl;
            continue;
        } else if (tmp == 2) {
            cout << 3 << endl;
            continue;
        }

        for (int j = 3; j <= tmp; j++) {
            fn = f2 + 2 * f1;
            f1 = f2;
            f2 = fn;
        }

        cout << fn << endl;

    }

    return 0;
}

// f1 = 1
// f2 = 3
// fn = f(n - 1) + 2f(n - 2)