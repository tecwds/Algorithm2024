//
// Created by wpan on 10/22/24.
//

#include <iostream>

// 函数用于打印移动步骤
void printMove(int from, int to) {
    std::cout << from << "," << from + 1 << "-->" << to << "," << to + 1 << std::endl;
}

// 递归函数用于计算和打印移动步骤
void moveChess(int n, int left, int right) {
    if (left >= right) return; // 如果没有更多的棋子需要移动，则返回
    // 计算当前移动的目标位置
    int target = 2 * n - (right - left);
    // 打印当前移动步骤
    printMove(left, target);
    // 递归移动剩余的棋子
    moveChess(n, right, target - 2);
}

int main() {
    int N;
    std::cin >> N; // 读取输入
    // 从最左边的黑子开始移动，直到最右边的黑子
    moveChess(N, 1, 2 * N - 1);
    return 0;
}
