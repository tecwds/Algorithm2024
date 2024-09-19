#include <iostream>
#include <cmath>
using namespace std;

long long a;
long long n;
long long m = 1;

int main() {

    cin >> a;

    while (++m) {
        long long pm = static_cast<long long>(pow(a, m)) % 1000;
        cout << "pm = " << pm << endl;
        while (++n && n < m) {
            if (pm == ((long long)pow(a, n) % 1000)) {
                cout << n << " " << m << endl;
                return 0;
            }
        }
    }

    return 0;
}