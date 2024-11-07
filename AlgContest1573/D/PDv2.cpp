//
// Created by wpan on 10/31/24.
//
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int n;
    while (cin >> n && n > 0) {
        if (n <= 4) {
            cout << 10 << endl;
            continue;
        }
        if (n <= 8) {
            cout << 10 + (n - 4) * 2 << endl;
        }
        double sum = 0;
        while (n > 8) {
            sum += 18;
            n -= 8;
        }
        if (n <= 4) {
            sum += n * 2.4;
        }
        else if (n <= 8) {
            sum += 10 + (n - 4) * 2;
        }

        cout << sum << endl;
    }

    return 0;
}


