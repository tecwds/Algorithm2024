//
// Created by wpan on 11/4/24.
//
#include <bits/stdc++.h>

using namespace std;

string s;
stack<char> stk;
stack<int> stk_num;
string str;
int pri[100];

bool is_calc(const char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool func() {
    stack<char> st;

    for (auto i : s) {
        if (i == '@') break;
        if (i == '(') st.push(i);
        else if (i == ')') {
            if (st.empty()) {
                return false;
            }
            st.pop();
        }
    }

    if (!st.empty())
        return false;

    for (int i = 0; i < s.length() - 1; ++i) {
        if (is_calc(s[i]) && is_calc(s[i + 1])) {
            return false;
        }
    }
    return true;
}

void init() {
    pri[')'] = 1; //优先级最低，也就是可以实现遇到左括号之前全部出栈
    pri['+'] = 2;
    pri['-'] = 2;
    pri['*'] = 3;
    pri['/'] = 3;
    pri['('] = 4; //优先级最高，可以实现左括号直接进栈
}


void transform() {
    bool numStatus = true;
    int num = 0;
    for (const auto i : s) {
        if (i == '@')
            break;
        if (i >= '0' && i <= '9') {
            numStatus = true;
            num = num * 10 + (i - '0');
        } else if (i == '(') {
            if (numStatus) {
                str += (to_string(num) + " ");
                num = 0;
                numStatus = false;
            }
            stk.push(i);
        } else if (i == ')') {
            if (numStatus) {
                str += (to_string(num) + " ");
                num = 0;
                numStatus = false;
            }
            while (!stk.empty() && stk.top() != '(') {
                str += stk.top();
                stk.pop();
            }
            if(!stk.empty()) stk.pop();
        } else {
            if (numStatus) {
                str += (to_string(num) + " ");
                num = 0;
                numStatus = false;
            }
            while (!stk.empty() && pri[i] <= pri[stk.top()] && stk.top() != '(') {
                str += stk.top();
                stk.pop();
            }
            stk.push(i);
        }
    }
    if (numStatus) {
        str += (to_string(num) + " ");
    }
    while (!stk.empty()) {
        str += stk.top();
        stk.pop();
    }
}

void cal() {
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            int num = 0;
            while (str[i] != ' ') {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            stk_num.push(num);
        } else {
            //运算
            const int a = stk_num.top();
            stk_num.pop();
            const int b = stk_num.top();
            stk_num.pop();
            switch (str[i]) {
                case '+':
                    stk_num.push(b + a);
                    break;
                case '-':
                    stk_num.push(b - a);
                    break;
                case '*':
                    stk_num.push(b * a);
                    break;
                case '/':
                    stk_num.push(b / a);
                    break;
                default: ;
            }
        }
    }
}


int main() {
    cin >> s;
    //判断表达式合法性
    if (!func()) {
        cout << "NO";
        return 0;
    }
    //初始优先级数组
    init();
    //将中缀转化为后缀字符串str
    transform();
    //计算后缀表达式str的值
    cal();

    if (const int res = stk_num.top(); res < 0) {
        cout << "NO" << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}



