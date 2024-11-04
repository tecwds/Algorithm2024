//
// Created by wpan on 11/4/24.
//
#include<bits/stdc++.h>
using namespace std;

constexpr int maxn = 1010;
int s[maxn];
int a[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int top = 0;
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        while (cur <= a[i]) s[++top] = cur++;
        if (s[top] == a[i]) top--;
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
