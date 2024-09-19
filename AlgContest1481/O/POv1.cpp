#include <iostream>

using namespace std;

int n;
int num[11];
int x;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cin >> x;

    for (int i = 0; i < n; i++) {
        if (i != x - 1) {
            cout << num[i] << " ";
        }
    }

    return 0;
}