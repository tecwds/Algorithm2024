//
// Created by wpan on 11/4/24.
//
#include<bits/stdc++.h>
using namespace std;

stack<char> st;

bool flag;

int main() {
    string s;
    cin >> s;
    for (auto c: s) {
        if (c == '(' || c == '[')st.push(c);
        else if (c == ')' || c == ']') {
            char p;
            if (c == ')')p = '(';
            if (c == ']')p = '[';
            if (st.empty() || st.top() != p)flag = 1;
            else st.pop();
        }
    }
    if (!st.empty() || flag) cout << "Wrong" << '\n';
    else cout << "OK" << '\n';
    return 0;
}
