// 问题 D: N个选项的问题
#include <iostream>

using namespace std;

// N个选项
int n;

// 数字 A
int a;

// 数字 B
int b;

// 结果集
int c_res[333];

// 下表
int index_;

int main()
{

    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) {
        cin >> c_res[i];

        if (a + b == c_res[i]) {
            index_ = i;
        }
    }
    
    cout << index_ << endl;
    
    return 0;
}