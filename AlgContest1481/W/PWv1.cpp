#include <iostream>
#include <cmath>
using namespace std;

int is_prime(long long n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;

// while (scanf("&d", &n) != EOF) {
while (cin >> n) {
    if (n <= 1) {
        cout << "no" << endl;
        continue;
    }

    if (is_prime(n)) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
}
    return 0;
}