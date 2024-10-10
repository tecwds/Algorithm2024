//
// Created by wpan on 10/10/24.
//
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 素数表
int prime_arr[] = {
    2, 3, 5, 7, 11, 13,
    17, 19, 23, 29, 31, 37
};
set<int> prime;

int n;
int cnt;
bool vis[20];
int a[20];

bool prime_sum(const int x, const int y) {
    return prime.end() != prime.find(x + y);
}

void my_print() {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void dfs(const int k) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i] && prime_sum(a[k - 1], i)) {
            a[k] = i;
            vis[i] = true;
            if (k == n - 1) {
                if (prime_sum(a[n - 1], a[0])) my_print();
            } else {
                dfs(k + 1);
            }
            vis[i] = false;

        }
    }
}

int main() {
    for (const auto i: prime_arr) {
        prime.insert(i);
    }

    while (cin >> n) {
        cnt++;

        cout << "Case " << cnt << ":" << endl;
        memset(vis, 0, sizeof(vis));

        if (n % 2 == 0) {
            a[0] = 1;
            vis[1] = true;
            dfs(1);
        }

        cout << endl;
    }


    return 0;
}
