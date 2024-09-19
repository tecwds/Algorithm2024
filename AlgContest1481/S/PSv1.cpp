#include <iostream>
#include <algorithm>
using namespace std;

// 学生人数
int n;


// 学生的能力值
int q_ab[111];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> q_ab[i];
    }

    // sort
    sort(q_ab + 1, q_ab + n + 1);

    int res = 0;

    for (int i = 1; i <= n; i += 2) {
        res += q_ab[i + 1] - q_ab[i];
    }

    cout << res << endl;


    



    return 0;
}