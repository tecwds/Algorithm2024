//
// Created by wpan on 11/4/24.
//
#include <complex>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;


// 运算符优先级函数
int precedence(const char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    string expression;

    cin >> expression;

    stack<int> nums;
    stack<char> ops;

    const int n = static_cast<int>(expression.length());

    for (int i = 0; i < n; ++i) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            int num = 0;
            while (i < n && expression[i] >= '0' && expression[i] <= '9') {
                num = num * 10 + (expression[i++] - '0');
            }
            --i; // 回退一个位置
            nums.push(num);
        } else if (expression[i] == '(') {
            ops.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                const int b = nums.top();
                nums.pop();
                const int a = nums.top();
                nums.pop();
                const char op = ops.top();
                ops.pop();
                int result = 0;
                switch (op) {
                    case '+': result = a + b;
                        break;
                    case '-': result = a - b;
                        break;
                    case '*': result = a * b;
                        break;
                    case '/': result = a / b;
                        break;
                    case '^': result = static_cast<int>(pow(a, b));
                        break;
                    default: ;
                }
                nums.push(result);
            }
            ops.pop(); // 弹出左括号
        } else if (expression[i] == '+' || expression[i] == '-' ||
                   expression[i] == '*' || expression[i] == '/' ||
                   expression[i] == '^') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                char op = ops.top();
                ops.pop();
                int result = 0;
                switch (op) {
                    case '+': result = a + b;
                        break;
                    case '-': result = a - b;
                        break;
                    case '*': result = a * b;
                        break;
                    case '/': result = a / b;
                        break;
                    case '^': result = static_cast<int>(pow(a, b));
                        break;
                    default: ;
                }
                nums.push(result);
            }
            ops.push(expression[i]);
        }
    }

    while (!ops.empty()) {
        const int b = nums.top();
        nums.pop();
        const int a = nums.top();
        nums.pop();
        const char op = ops.top();
        ops.pop();
        int result = 0;
        switch (op) {
            case '+': result = a + b;
                break;
            case '-': result = a - b;
                break;
            case '*': result = a * b;
                break;
            case '/': result = a / b;
                break;
            case '^': result = static_cast<int>(pow(a, b));
                break;
            default: ;
        }
        nums.push(result);
    }

    cout << nums.top() << endl;

    return 0;
}
