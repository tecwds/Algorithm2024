#include<cstdio>
#include <iostream>
using namespace std;
long long min_x, min_y, max_x, max_y;

int main() {
    long long ci, x, y;
    cin >> ci;
    for (int i = 0; i < ci; i++) {
        cin >> x >> y;
        if (!i) {
            max_x = min_x = x;
            max_y = min_y = y;
        } else {
            if (min_x > x)min_x = x;
            if (min_y > y)min_y = y;
            if (max_x < x)max_x = x;
            if (max_y < y)max_y = y;
        }
    }
    const long long mk = (max_x - min_x) > (max_y - min_y) ? (max_x - min_x) : (max_y - min_y);

    cout << mk * mk << endl;
    return 0;
}
