#include <iostream>
using namespace std;

int main() {
    int n;
    int m;
    int oil[105];
    int sum = 0;

    cin >> n >> m;

    for (int j = 0; j < n; j++) {
        cin >> oil[j];
        sum += oil[j];
    }

    if (sum < m) {
        cout << "no" << endl;
        return 0;
    }

    sum = 1 << n;

    for (int i = 0; i < sum; i++) {
        int t = 0;
        int t2 = i;

        for (int j = 0; j < n; j++) {
            if (t2 & 1) t += oil[j];
            t2 >>= 1;
        }
        if (t == m) {
            cout << "yes" << endl;
            return 0;
        }
    }

    cout << "no" << endl;
    return 0;    
}