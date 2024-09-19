#include <iostream>

using namespace std;

int res[21] = {
    0, 3, 7, 17
};

int main() {
    int n;

    cin >> n;

    long long f1 = 3;
    long long f2 = 7;
    long long fn = 0;

    // 3 7 17 
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == 1) {
            cout << 3 << endl;
            continue;
        } else if (tmp == 2) {
            cout << 7 << endl;
            continue;
        }
        // 3 7 17
        for (int j = 3; j <= tmp; j++) {
            fn = 2 * f2 + f1;
            f1 = f2;
            f2 = fn;
            // f1 = f2;
        }

        cout << fn << endl;

        f1 = 3;
        f2 = 7;
        fn = 0;
        
    }

    return 0;
}