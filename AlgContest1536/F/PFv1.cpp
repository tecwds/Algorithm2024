#include <iostream>
using namespace std;

int func(int oil[], int n, int m, int index, int sum){
    if(index == n){
        return sum;
    }
    int t = func(oil, n, m, index + 1, sum);
    if(t > m){
        return -1; // 如果已经超过m了，就返回一个不可能的值
    }
    int t2 = func(oil, n, m, index + 1, sum + oil[index]);
    if(t2 == m){
        return m; // 找到符合条件的组合
    }else{
        return -1; // 没找到，继续找下一个
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int oil[105];
    for(int j = 0; j < n; j++){
        cin >> oil[j];
    }

    int result = func(oil, n, m, 0, 0);

    if(result >= m){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }

    return 0;
}
