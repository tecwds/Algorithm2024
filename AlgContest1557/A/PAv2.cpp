//
// Created by wpan on 10/15/24.
//
#include <iostream>
#include <vector>
using namespace std;

int a[9];
bool b[9];
bool c[17];
bool d[17];

int cnt;

void print() {
    cout << "<" << ++cnt << ">";

    // 输出
    for (int i = 1; i <= 8; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void dfs(int k) {
  if (k == 9) {
        print();
  } else {
      for (int i = 1; i <= 8; ++i) {
          // 八皇后问题
          if (!b[i] && !c[k - i + 7] && !d[k + i]) {
              a[k] = i;
              b[i] = true;
              c[k - i + 7] = true;
              d[k + i] = true;
              dfs(k + 1);
              b[i] = false;
              c[k - i + 7] = false;
              d[k + i] = false;
          }
      }
  }
}

int main() {
    // 实现
    dfs(1);
    return 0;
}
