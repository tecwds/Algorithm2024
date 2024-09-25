#include <iostream>
#include <unordered_map>

using namespace std;

pair<int, int> find_min_n_m(int a) {
    unordered_map<int, int> last_three_digits;
    long long power = a;
    int n = 1;

    while (true) {
        int mod = power % 1000; // 取最后三位数字
        if (last_three_digits.find(mod) != last_three_digits.end()) {
            // 找到相同的最后三位数字，返回结果
            return {last_three_digits[mod], n};
        }
        last_three_digits[mod] = n; // 存储当前幂次的最后三位数字及其索引
        power = (power * a) % 1000; // 计算下一个幂次的最后三位数字
        n++;
    }
}

int main() {
    int a;
    cin >> a; // 读取输入的整数 a

    pair<int, int> result = find_min_n_m(a);
    cout << result.first << " " << result.second << endl; // 输出 n 和 m

    return 0;
}
