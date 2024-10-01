#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<char, int>> statements(n);

    // 初始化搜索范围
    int left = 0;
    int right = static_cast<int>(1e9);

    // 读取牛的说法
    for (size_t i = 0; i < n; ++i) {
        char type;
        int num;
        cin >> type >> num;
        statements[i] = {type, num};

        // 更新搜索范围
        if (type == 'L') {
            right = min(right, num);
        } else if (type == 'G') {
            left = max(left, num);
        }
    }

    int count = n; // 初始化撒谎奶牛的最大可能数量

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int lying = 0;

        // 计算在mid位置撒谎的奶牛数量
        for (const auto& [type, num] : statements) {
            if ((type == 'L' && mid > num) || (type == 'G' && mid < num)) {
                lying++;
            }
        }

        // 更新撒谎奶牛的最小数量
        count = min(count, lying);

        // 二分查找，根据撒谎的奶牛数量调整搜索范围
        if (lying > 0) {
            // 如果在mid位置有撒谎的奶牛，需要继续查找
            int lying_mid = 0;
            for (const auto& [type, num] : statements) {
                if ((type == 'L' && mid + 1 > num) || (type == 'G' && mid + 1 < num)) {
                    lying_mid++;
                }
            }

            // 比较在mid和mid+1位置撒谎的奶牛数量，以决定搜索方向
            if (lying_mid < lying) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else {
            // 如果在mid位置没有撒谎的奶牛，则已经找到了最优解
            break;
        }
    }

    cout << count << endl;
    return 0;
}
