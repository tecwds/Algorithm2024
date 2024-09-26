#include <iostream>
using namespace std;

long long ni(long long n) {
    if (n == 0) return 1;
    return n * ni(n - 1);
}

int main() {
    int n;
    cin >> n;

    cout << ni(n) << endl;

    return 0;
}