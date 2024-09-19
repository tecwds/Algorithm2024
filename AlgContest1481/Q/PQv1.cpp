#include <iostream>

using namespace std;

int res[1010];

// 个数
int n;


int main() {

    cin >> n;

    int temp;

    cin >> temp;

    for (int i = 0; i < n - 1; i++) {
        cin >> res[i];
    }

    res[n - 1] = temp;


    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }

    return 0;
}