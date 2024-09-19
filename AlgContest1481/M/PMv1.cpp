#include <iostream>
#include <algorithm>

using namespace std;

int n;
int hbn[6000];

// // 四个素因子
// int a = 2;
// int b = 3;
// int c = 5;
// int d = 7;
// 素因子数字
void get_hbn() {
    hbn[1] = 1;

    int a = 1; // 2
    int b = 1; // 3
    int c = 1; // 5
    int d = 1; // 7

    for (int i = 2; i <= 5842; i++) {
        // 一个数是丑数 2x, 3x, 5x, 7x 也是丑数（百度的）
        // 从 1 开始，从小到大遍历丑数
        hbn[i] = min (
            hbn[a] * 2,
            min (
                hbn[b] * 3,
                min (
                    hbn[c] * 5,
                    hbn[d] * 7
                )
            )
        );

        if (hbn[i] == hbn[a] * 2) a++;
        if (hbn[i] == hbn[b] * 3) b++;
        if (hbn[i] == hbn[c] * 5) c++;
        if (hbn[i] == hbn[d] * 7) d++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // cin >> n;

    get_hbn();

    // for (auto i : hbn) {
    //     cout << i << " ";
    // }

    do {
        cin >> n;

        if (!n) {
            return 0;
        }
        // 最后一个数字是 1, 2, 3 对应 st, nd, rd
        // 最后两位数不是 11, 12, 13
        if (n % 10 == 1 && n % 100 != 11) {
            cout << "The " << n << "st humble number is " << hbn[n] << "." << endl;
        }
        else if (n % 10 == 2 && n % 100 != 12) {
            cout << "The " << n << "nd humble number is " << hbn[n] << "." << endl;
        }
        else if (n % 10 == 3 && n % 100 != 13) {
            cout << "The " << n << "rd humble number is " << hbn[n] << "." << endl;
        }
        else {
            cout << "The " << n << "th humble number is " << hbn[n] << "." << endl;
        }

    } while (n);
    
    return 0;
}