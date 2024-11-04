//
// Created by wpan on 11/4/24.
//
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    int n;
    int nums[105];
    while (cin >> n) {
        if (n == 0) break;
        for (int index = 0; index < n; index++) cin >> nums[index]; // 输入数组
        stack<int> st;
        int index = 0;
        for (int i = 1; i <= n; i++) {
            // 判断出栈合法性
            st.push(i);
            while (!st.empty() && st.top() == nums[index]) {
                st.pop();
                index++;
            }
        }
        if (st.empty() && index == n) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
