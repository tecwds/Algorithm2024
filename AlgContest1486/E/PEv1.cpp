#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;

    // 最后一天剩一个枣
    int remain = 1;

    for (int day = 1; day < n; day++) {
        remain = (remain + 1) * 2;
    }

    cout << remain << endl;

    return 0;
}
