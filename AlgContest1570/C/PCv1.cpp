#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

int main(int argc, char *argv[]) {
    string a;
    getline(cin, a);
    int num = 0;
    for (int i = 0; a[i] != '@'; i++) {
        if (a[i] <= '9' && a[i] >= '0') {
            num = num * 10 + (a[i] - '0');
        } else if (a[i] == '.') {
            st.push(num);
            num = 0;
        } else {
            int x, y;
            y = st.top(), st.pop();
            x = st.top(), st.pop();
            switch (a[i]) {
                case '+':
                    st.push(x + y);
                    break;
                case '-':
                    st.push(x - y);
                    break;
                case '*':
                    st.push(x * y);
                    break;
                case '/':
                    st.push(x / y);
                    break;
                default: break;
            }
        }
    }
    cout << st.top() << '\n';
    return 0;
}
