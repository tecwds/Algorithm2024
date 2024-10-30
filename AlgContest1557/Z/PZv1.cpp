//
// Created by wpan on 10/31/24.
//
#include<bits/stdc++.h>
using namespace std;

void print(string s) {
    for (char c: s)cout << c << ' ';
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++)s += i + '0';
    print(s);
    while (next_permutation(s.begin(), s.end()))
        print(s);
    return 0;
}
