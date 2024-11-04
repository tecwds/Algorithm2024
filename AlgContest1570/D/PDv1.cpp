//
// Created by wpan on 11/4/24.
//
#include <iostream>
#include <stack>
using namespace std;

stack<char> st;

int main(int argc, char *argv[]) {
    string str;
    while (cin >> str) {
        bool flag = false;
        for (auto c : str) {
            if (c == '(') st.push(c);
            else if (c == ')') {
                if (!st.empty()) st.pop();
                else flag = true;
            }
        }
        if (!st.empty() || flag) cout << "NO" << "\n";
        else cout << "YES" << "\n";
        str.clear();
    }
    return 0;
}
