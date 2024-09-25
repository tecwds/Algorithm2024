#include <iostream>
#include <vector>
using namespace std;

vector<int> mul(const vector<int>& vec, int num) {
    vector<int> res;
    int carry = 0;

    for (size_t i = 0; i < vec.size(); i++) {
        int product = vec[i] * num + carry;
        res.push_back(product % 10);
        carry = product / 10;
    }

    while (carry) {
        res.push_back(carry % 10);
        carry /= 10;
    }

    return res;
}

vector<int> fact(int n) {
    vector<int> result;
    result.push_back(1);

    for (int i = 2; i <= n; i++) {
        result = mul(result, i);
    }

    return result;
}

int main() {
    int n;

    cin >> n;

    vector<int> res = fact(n);

    for (auto it = res.rbegin(); it != res.rend(); it++) {
        cout << *it;
    }

    cout << endl;

    return 0;
}