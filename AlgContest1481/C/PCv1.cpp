#include <iostream>
#include <string>

using namespace std;

// 输入
string input;

// 总 GPA
double total_gpa;

// 学科数量
int sub_num;

int main()
{
    cin >> input;

    // int lenght = input.size();

    for (auto ch : input)
    {
        switch (ch)
        {
        case '+': 
            total_gpa += 0.3;
            break;
        case '-':
            total_gpa -= 0.3;
            break;
        case 'A':
            total_gpa += 4;
            sub_num++;
            break;
        case 'B':
            total_gpa += 3;
            sub_num++;
            break;
        case 'C':
            total_gpa += 2;
            sub_num++;
            break;
        case 'D':
            total_gpa += 1;
            sub_num++;
            break;
        }
    }

    printf("%.2lf", total_gpa / sub_num);

    return 0;
}