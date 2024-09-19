#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 整数转进制
string number2scale(
    int num,
    // 进制数
    int s
) {
    
    string chars = "0123456789";

    string result;

    do {
        result = chars[num % s] + result;
        num /= s;
    } while(num > 0);

    return result;
}

bool is_palindromes(int num) {
    int is_pal_num = 0;

    // s: 进制（二进制到十进制）
    for (int s = 2; s < 11; s++) {
        string str_nums = number2scale(num, s);

        bool is_pal = true;
        int len = str_nums.length();
        for (int i = 0; i < len / 2; i++) {
            if (str_nums[i] != str_nums[len - 1 - i]) {
                is_pal = false;
                break;
            }
        }

        if (is_pal) {
            // 如果这个进制是回文数，累加
            is_pal_num++;
        }

        if (is_pal_num == 2) {
            // 没有必要判断多的进制是否是回文数
            return true;
        }
    }

    return is_pal_num > 2;
}


int main() {

    ifstream input("dualpal.in");
    ofstream output("dualpal.out");

    int n;
    int s;

    // 从文件读取 n, s
    input >> n >> s;

    for (int i = 0, num = s + 1; i < n; num++) {
        if (is_palindromes(num)) {
            output << num << endl;
            i++;
        }
    }

    output.close();
    input.close();

    return 0;
}