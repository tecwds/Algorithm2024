#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 偶数，奇数
vector<int>* ou = new vector<int>;
vector<int>* ji = new vector<int>;

int main() {
    int n = 0;
    for (int i = 0; i < 10; i++) {
        cin >> n;

        if (n % 2 == 0) {
            // 偶数
            ou->push_back(n);
        } else {
            ji->push_back(n);
        }
    }

    // sort
    // 反向排序 大->小
    sort(ji->rbegin(), ji->rend());

    sort(ou->begin(), ou->end());

    for (auto i: *ji) {
        cout << i << " ";
    }
    for (auto i: *ou) {
        cout << i << " ";
    }

    return 0;
}