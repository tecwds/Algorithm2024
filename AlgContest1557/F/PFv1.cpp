//
// Created by wpan on 10/30/24.
//
#include <iostream>
using namespace std;
int a[505] = {0};
int ans[27];
int T;
int cont = {0};

void dfs(const int ss) {
    if (ss == T) {
        cont++;
        for (int i = 0; i < T; i++)
            cout << static_cast<char>(a[i] + 'a');
        cout << endl;
    } else {
        for (int i = 0; i < 26; i++) {
            if (ans[i] > 0) {
                a[ss] = i;
                ans[i]--;
                dfs(ss + 1);
                ans[i]++;
            }
        }
    }
}

int main() {
    while (cin >> T) {
        cont = 0;
        char x;
        for (int i = 0; i < T; i++) {
            cin >> x;
            ans[x - 'a']++;
        }
        dfs(0);
        cout << cont << endl;
    }
    return 0;
}
