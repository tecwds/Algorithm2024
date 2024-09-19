#include <iostream>
using namespace std;
// l < r
int l;
int r;

// 是否是平衡树
bool is_par(int num) {
    // 1 - 9
    int times[10] = {0};

    while (num > 0) {
        times[num % 10]++;
        num /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (times[i] != 0 && times[i] != i) return false;
    }
    return true;
}


int main() {
    cin >> l >> r;

    long long res = 0;

    for (int i = l; i <= r; i++) {
        // res += is_par(i) ? i : 0;
        if (is_par(i)) {
            res += i;
        }
    }

    cout << res << endl;

    return 0;
}