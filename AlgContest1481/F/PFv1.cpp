#include <iostream>
#include <cmath>

using namespace std;

// 整数 n
long long n;

// 最大平方因子
long long max_x = 1;


int main() {

    cin >> n;

    int half_ = sqrt(n);

    for (int i = 2; i <= half_; i++) {
        // 枚举平方因子(i*i作为整体，是一个因子)
        if (n % (i * i) == 0) {
            // i 在递增，因此 max_x 会越来越大
            max_x = i * i;
        }
    }

    cout << max_x << endl;

    return 0;
}