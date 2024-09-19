#include <iostream>
using namespace std;

int n;
int nums[15];
int x;
int y;

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> x >> y;

    // 移动
    for (int i = n; i >= x; i--) {
        nums[i] = nums[i - 1];
    }

    nums[x - 1] = y;

    for (int i = 0; i <= n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}