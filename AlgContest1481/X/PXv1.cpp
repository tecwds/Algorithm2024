// 问题 X: 素数个数
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX = 3e7 + 10;

// 素数表
bool table[MAX];

// 个数
int nums;

void find_prime(int n) {
    table[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (table[i] == 1) {
            continue;   
        }
        // nums++;
        for (int j = i + i; j <= n; j += i) {
            table[j] = 1;
        }
    }
    // 去掉 2、3
    // for (int i = 2;)

    // find nums
    for (int i = 1; i <= n; i++) {
        if (table[i] == 0) nums++;
    }
}



int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    find_prime(n);

    cout << nums << endl;
    // cout << find_prime(n) << endl;

    return 0;
}