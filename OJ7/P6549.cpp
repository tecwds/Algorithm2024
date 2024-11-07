#include <iostream>
using namespace std;

int tel(long long int a);

int main() {
    long long int n;
    cin >> n;
    int sum = 0;
    for (long long int i = n; i <= 8888888888; i++) {
        if ((tel(i)) && (i != n)) {
            printf("%d", sum);
            return 0;
        } else {
            sum++;
        }
    }
}

int tel(long long int a) {
    int t = 0;
    if (a < 0) {
        a = a * (-1);
    }
    while (a != 0) {
        const int k = a % 10;
        a = a / 10;
        if (k == 8) {
            t = 1;
            return 1;
        }
    }
    return 0;
}
