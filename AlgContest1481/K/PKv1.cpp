#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 读取正方形图案
vector<vector<char>> readPattern(int N) {
    vector<vector<char>> pattern(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> pattern[i][j];
        }
    }
    return pattern;
}

// 旋转90度
vector<vector<char>> rotate90(const vector<vector<char>>& pattern) {
    int N = pattern.size();
    vector<vector<char>> rotated(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            rotated[j][N - 1 - i] = pattern[i][j];
        }
    }
    return rotated;
}

// 水平翻转
vector<vector<char>> reflect(const vector<vector<char>>& pattern) {
    int N = pattern.size();
    vector<vector<char>> reflected(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            reflected[i][N - 1 - j] = pattern[i][j];
        }
    }
    return reflected;
}

// 检查两个图案是否相同
bool areSame(const vector<vector<char>>& a, const vector<vector<char>>& b) {
    return a == b;
}

// 查找最小转换方法
int findTransform(const vector<vector<char>>& original, const vector<vector<char>>& target) {
    vector<vector<char>> rotated90 = rotate90(original);
    vector<vector<char>> rotated180 = rotate90(rotated90);
    vector<vector<char>> rotated270 = rotate90(rotated180);
    vector<vector<char>> reflected = reflect(original);
    vector<vector<char>> reflected90 = rotate90(reflected);
    vector<vector<char>> reflected180 = rotate90(reflected90);
    vector<vector<char>> reflected270 = rotate90(reflected180);

    if (areSame(rotated90, target)) return 1;
    if (areSame(rotated180, target)) return 2;
    if (areSame(rotated270, target)) return 3;
    if (areSame(reflected, target)) return 4;
    if (areSame(reflected90, target) || areSame(reflected180, target) || areSame(reflected270, target)) return 5;
    if (areSame(original, target)) return 6;
    return 7;
}

int main() {
    int N;
    cin >> N;

    vector<vector<char>> original = readPattern(N);
    vector<vector<char>> target = readPattern(N);

    int transform = findTransform(original, target);
    cout << transform << endl;

    return 0;
}
