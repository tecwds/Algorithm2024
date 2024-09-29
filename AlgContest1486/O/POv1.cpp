#include <iostream>

using namespace std;
const int N = 110;

int n;
int minn;
int maxx = 100000;
int op[N];
int dw[N];
int uw[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        string t;
        cin >> t >> dw[i] >> uw[i];

        if (t == "on") op[i] = 1;
        else if (t == "none") op[i] = 2;
        else op[i] = 3;
    }

    //反着遍历高速公路，得出第一公里前车流量的上限和下限
    for (int i = n; i >= 1; i--) {
        if (op[i] == 1) {
            minn -= uw[i];
            maxx -= dw[i];
            minn = max(minn, 0);
            maxx = max(maxx, 0);
        } else if (op[i] == 2) {
            minn = max(minn, dw[i]);
            maxx = min(maxx, uw[i]);
        } else {
            minn += dw[i];
            maxx += uw[i];
        }
    }
    cout << minn << " " << maxx << endl;
    minn = 0;
    maxx = 100000;
    for (int i = 1; i <= n; i++) {
        if (op[i] == 1) {
            minn += dw[i];
            maxx += uw[i];
        } else if (op[i] == 2) {
            minn = max(minn, dw[i]);
            maxx = min(maxx, uw[i]);
        } else {
            minn -= uw[i];
            maxx -= dw[i];
            minn = max(minn, 0);
            maxx = max(maxx, 0);
        }
    }
    cout << minn << " " << maxx << endl;

    return 0;
}
