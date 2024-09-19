#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// 石头的位置
// 计数
int pos_[4];

// 交换的位置
int shell[4] = {0, 1, 2, 3};

int n;

int a;
int b;
int pos;

int main() {

    cin >> n; 

    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> pos;
        swap(shell[a], shell[b]);
        pos_[shell[pos]]++;
    }

    // for (auto i: pos_) {
    //     cout << i << endl;
    // }

    cout << max(pos_[1], max(pos_[2], pos_[3]));

    return 0;
}