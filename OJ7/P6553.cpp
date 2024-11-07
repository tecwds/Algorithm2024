#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int a, b, c, d, e, f, x, y, z, ans = 1e9;
    std::cin >> a >> b >> c >> d >> e >> f >> x >> y >> z;

    for (int i = max(f + 1 - b, 0); i <= 200; ++i)
        for (int j = 0; j <= 200; ++j) {
            int k = (d - 1) / (b + i - f) + 1;
            k = max(k * max(0, e - c - j) + 1 - a, 0);
            ans = min(ans, k * x + i * y + j * z);
        }
    cout << ans << endl;
}
