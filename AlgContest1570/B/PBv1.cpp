//
// Created by wpan on 11/4/24.
//
#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

int main() {
    int n;

    while (cin >> n) st.push(n);
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}