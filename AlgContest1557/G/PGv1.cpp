//
// Created by wpan on 10/30/24.
//
#include<bits/stdc++.h>
using namespace std;
int data[9999999];
bool visit[9999999];
int n;
int c;

bool choose(const int n) {
    int p = 0;
    int sum = 0;
    while (p >= 0) {

        if (!::visit[p]) {
            ::visit[p] = true;
            sum += ::data[p];
            if (c == sum)
                return true;
            else if (c < sum) {
                ::visit[p] = false;
                sum -= ::data[p];
            }
            p++;
        }
        if (p >= n) {
            while (::visit[p - 1]) {
                p--;
                ::visit[p] = false;
                if (p < 1) return false;
            }
            while (!::visit[p - 1]) {
                p--;
                if (p < 1) return false;
            }
            sum -= ::data[p - 1];
            ::visit[p - 1] = false;
        }
    }
    return false;
}

signed main() {
    cin >> n >> c;

    for (int i = 0; i < n; i++)
        cin >> ::data[i];

    if (choose(n)) {
        int first = 1;
        for (int i = 0; i < n; i++)
            if (::visit[i]) {
                if (first) first = 0;
                else cout << " ";
                cout << ::data[i];
            }
        cout << endl;
    } else cout << "No Solution!" << endl;
}
