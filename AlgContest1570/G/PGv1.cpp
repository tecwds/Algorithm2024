//
// Created by wpan on 11/4/24.
//
#include<bits/stdc++.h>
using namespace std;

stack<char> st;

int main() {
    int t;
    cin >> t;
    map<char, int> mp;
    mp['<'] = 1;
    mp['('] = 2;
    mp['['] = 3;
    mp['{'] = 4;
    map<char, char> mmp;
    mmp['<'] = '>';
    mmp['('] = ')';
    mmp['['] = ']';
    mmp['{'] = '}';

    while (t--) {
        string s;
        cin >> s;
        bool flag = false;
        for (char c: s) {
            if (c == '(' || c == '[' || c == '<' || c == '{') {
                if (st.empty()) {
                    st.push(c);
                } else {
                    char p = st.top();
                    if (mp[p] < mp[c]) {
                        flag = true;
                        break;
                    } else {
                        st.push(c);
                    }
                }
            } else {
                if (st.empty()) {
                    flag = true;
                    break;
                } else {
                    if (char p = st.top(); mmp[p] != c) {
                        flag = true;
                        break;
                    } else st.pop();
                }
            }
        }
        if (!st.empty() || flag)cout << "NO" << '\n';
        else cout << "YES" << '\n';
        stack<char>().swap(st);
    }
    return 0;
}
