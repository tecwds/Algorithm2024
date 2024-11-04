//
// Created by wpan on 11/4/24.
//
#include <iostream>
#include <stack>
using namespace std;

stack<char> st;

bool flag;

int main() {
    string s;
    cin >> s;
    for (auto c: s) {
        if (c == '(')st.push(c);
        else if (c == ')') {
            if (st.empty())flag = 1;
            else st.pop();
        }
    }
    if (!st.empty() || flag) cout << "NO" << '\n';
    else cout << "YES" << '\n';
    return 0;
}
