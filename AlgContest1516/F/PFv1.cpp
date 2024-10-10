//
// Created by wpan on 10/10/24.
//
#include <iostream>
using namespace std;

// 1x1 -> 1
// 1x2 -> 2
// 1x3 -> 4
// 1x4 -> 7
// ......

// int func(int n) {
//
// }

int a[40];

int main() {

    int n;
    cin >> n;

    a[1] = 1;
    a[2] = 2;
    a[3] = 4;

    for (int i = 4; i <= n; ++i) {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }

    cout << a[n] << endl;



    return 0;
}
