#include <iostream>

using namespace std;

int n;

int nums[111];

int len;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n){
        // cout << "len = " << len << endl;
        nums[len++] = n;
    }

    // bool flag = true;
    for (int i = len - 1; i >= 0; --i) {
        cout << nums[i] << " ";
    }

    return 0;
}