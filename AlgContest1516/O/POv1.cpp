//
// Created by wpan on 10/16/24.
//
#include <iostream>
using namespace std;
long long wc[55] = {
    0, 1, 2, 3, 5,
    8, 13, 21, 34, 55, 89,
    144, 233, 377, 610, 987,
    1597, 2584, 4181, 6765, 10946,
    17711, 28657, 46368, 75025, 121393,
    196418, 317811, 514229, 832040, 1346269,
    2178309, 3524578, 5702887, 9227465, 14930352,
    24157817, 39088169, 63245986, 102334155, 165580141,
    267914296, 433494437, 701408733, 1000000000
};
long long js = 2;

struct S {
    int b;
    int e;
} cw[55];

int main() {
    long long ak;

    cin >> ak;

    cw[1].b = 1;
    cw[1].e = 2;

    if (ak == 1) {
        cout << "m=1" << endl << "n=1";
    }

    for (int i = 2; i <= 43; i++) {
        cw[i].b = cw[i - 1].e + 1;
        cw[i].e = cw[i].b + wc[i] - 1;
    }

    cw[43].e = 1000000000;

    for (int i = 1; i <= 43; i++) {
        if (ak <= cw[i].e && ak >= cw[i].b) {
            cout << "m=" << wc[i] << endl << "n=" << wc[i + 1];
        }
    }
    return 0;
}
