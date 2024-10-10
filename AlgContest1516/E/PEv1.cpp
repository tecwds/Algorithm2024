#include <iostream>

using namespace std;

long long cnn(int n) {
    if (n == 1) return 0L;
    if (n == 2) return 1L;
    else return (n - 1) * (cnn(n - 1) + cnn(n - 2));
}

int main() {

    int n;

    while (cin >> n) {
        cout << cnn(n) << endl;
    }

    return 0;
}