#include <iostream>

using namespace std;

int s1;
int s2;
int a[4];
int b[4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int i;
    int j;

    for (i = 0; i < 3; i++, cin >> a[i] >> b[i]) {
    }
    for (i = 1; i <= 100; ++i) {
        s1 = (i - 1) % 3 + 1;

        if (s1 == 3) { s2 = 1; } else { s2 = s1 + 1; }

        int min = std::min(a[s2] - b[s2], b[s1]);

        b[s1] -= min;
        b[s2] += min;
    }

    // for (const auto i_ : b) cout << i_ << endl;
    for (int i_ = 1; i_ < 4; ++ i_) cout << b[i_] << endl;

    return 0;
}
