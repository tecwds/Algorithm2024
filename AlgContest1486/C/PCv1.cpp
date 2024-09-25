#include <iostream>
using namespace std;

long long a0;
long long a1;
long long a2;
long long ax;
int main() {

    cin >> a0 >> a1 >> a2;

    cout << a0 << " ";
    cout << a1 << " ";
    cout << a2 << " ";

    for (int i = 3; i <= 20; i++) {
        ax = a0 + 2 * a1 + a2;
        cout << ax << " ";
        a0 = a1;
        a1 = a2;
        a2 = ax;
    }

    return 0;
}