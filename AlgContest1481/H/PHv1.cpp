// 问题 H: 最小最大对
#include <iostream>
#include <vector>
using namespace std;

// [1, n]
int n;

// 整数对的数量
int num;

vector<long long>* seq = new vector<long long>(500005);

int main() {
    cin >> n;

    // 序列
    seq->push_back(0)    ;
    long long temp = 0;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        seq->push_back(temp);
    }

    // 1 <= i <= j <= n

    for (long long i = 1; i < n; i++) {
        for (long long j = i + 1; j <= n; j++) {
            if (seq->at(i) > seq->at(j) && seq->at(i) == j && seq->at(j) == i) {
                num++;
            }
            else if (seq->at(i) < seq->at(j) && seq->at(i) == i && seq->at(j) == j) {
                num++;
            }
        }
    }

    cout << num << endl;
    
    return 0;
}