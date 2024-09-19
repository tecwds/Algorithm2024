#include <iostream>
#include <vector>
using namespace std;

vector<int>* vec = new vector<int>;

int n;

// x: 要插入的位置 y: 要插入的整数
int x;
int y;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cout << "?" << endl;
    cin >> n;

    int temp = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vec->push_back(temp);
    }

    cin >> x >> y;

    auto iter = vec->begin();
    advance(iter, x - 1);

    vec->emplace(iter, y);

    for (auto i : *vec) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}