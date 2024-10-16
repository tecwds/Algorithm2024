//
// Created by wpan on 10/16/24.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        // 初始区域数量
        int regions = 1;
        // 每条曲线增加的区域数量
        int added_regions = 2;
        for (int i = 1; i < n; ++i) {
            regions += added_regions;
            // 每增加一条曲线，新增的区域数增加2
            added_regions += 2;
        }
        cout << regions + 1 << endl;
    }
    return 0;
}