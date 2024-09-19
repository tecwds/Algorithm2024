#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10010;

// 素数表
// false    素数
// true     和数
bool table[MAX + 10] = {0};

void find_prime(int n) {
    // 2,3 是素数
    table[2] = false;
    table[3] = false;

    for (int i = 2; i <= n; i++) {
        if (table[i]) {
            // 如果是不素数，则跳过
            continue;
        }
        for (int j = i * 2; j <= n; j += i) {
            table[j] = true;
        }
    }
}

// 输入
int n;

int main() {
    find_prime(MAX);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n) {
        if (n <= 11) {
            cout << -1 << endl;
            continue;
        }

        bool first = true;

        for (int i = 11; i < n; i++) {
            // 个位数为 1
            // 是素数
            if (i % 10 == 1 && !table[i]) {
                if (first) {
                    first = false;
                    printf("%d", i);
                } else {
                    printf(" %d", i);
                }
            }
        }

        cout << endl;
    }
    
    return 0;
}
