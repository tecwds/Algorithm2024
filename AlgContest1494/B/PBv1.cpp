#include <iostream>
#include <map>
using namespace std;

// const int n_stick[10][2] = {
//     {0, 6},
//     {1, 2},
//     {2, 5},
//     {3, 5},
//     {4, 4},
//     {5, 5},
//     {6, 6},
//     {7, 3},
//     {8, 7},
//     {9, 6}
// };

// 数字对应的火柴棍
// map<int, int> n_stick;
int n_stick[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

// 获得数字对应的火柴棍
int total(int n) {
    int total = 0;
    do {
        total += n_stick[n % 10];
        n /= 10;
    } while(n);
    return total;
}

// 火柴棍的数量
int n;

// 加数 A
int a;

// 加数 B
int b;

// 统计能拼成的数量
int count;

int main() {
    // n_stick[0] = 6;
    // n_stick[1] = 2;
    // n_stick[2] = 5;
    // n_stick[3] = 5;
    // n_stick[4] = 4;
    // n_stick[5] = 5;
    // n_stick[6] = 6;
    // n_stick[7] = 3;
    // n_stick[8] = 7;
    // n_stick[9] = 6;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    // 减去加号和等号
    n = n - 4;

    for (a = 0; a < 1000; a++) {
        for (b = 0; b < 1000; b++) {
            if (total(a) + total(b) + total(a + b) == n) {
                ++::count;
            }
        }
    }

    cout << ::count << endl;

    return 0;
}