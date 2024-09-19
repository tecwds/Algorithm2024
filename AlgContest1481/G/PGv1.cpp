#include <iostream>
#include <string>

using namespace std;

// date before
string date_b;

// date after
string date_a;

// before - after
// 天数
int fate;

// 时间戳（天为单位）
long long m_mktime(
    int year,
    int mon,
    int day)
{
    long long mk = 0;

    // 找到闰年的个数
    // int run_nums = 0;

    int yn4 = year / 4;
    int yn100 = year / 100; // 排除
    int yn400 = year / 400;
    // int yn3200 = year/3200;  // 规则

    int run_nums = yn4 + yn400 - yn100;

    // 年
    mk += year * 365 + run_nums;

    // 某月份存在时间

    // 当前年是否是闰年
    int is_run = 0;

    // 日
    mk += day;

    // 

    // 月
    for (int i = mon - 1; i > 0; i--)
    {
        if (i == 2 && year % 100 != 0 && year % 400 == 0 || year % 4 == 0)
        {
            // 闰年
            mk += 29;
            continue;
        }

        switch (i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            mk += 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            mk += 30;
            break;
        case 2:
            mk += 28;
            break;
        }
    }


    return mk;
}

int main()
{
    cin >> date_b >> date_a;

    // long long l_a = stoi(date_a);
    // long long l_b = stoi(date_b);

    

    long long before = m_mktime(stoi(date_b.substr(0,4)), stoi(date_b.substr(4, 2)), stoi(date_b.substr(6,2)));
    long long after = m_mktime(stoi(date_a.substr(0,4)), stoi(date_a.substr(4, 2)), stoi(date_a.substr(6,2)));

    // cout << date_b.substr(0, 4) << endl;
    // cout << date_b.substr(4, 2) << endl;
    // cout << date_b.substr(6, 2) << endl;

    // cout << m_mktime(stoi(date_b.substr(0,4)), stoi(date_b.substr(4, 2)), stoi(date_b.substr(6,2))) << endl;
    // cout << m_mktime(stoi(date_a.substr(0,4)), stoi(date_a.substr(4, 2)), stoi(date_a.substr(6,2))) << endl;

    long long temp = 0;

    // 缝缝补补
    if (before > after) {
        temp = before;
        before = after;
        after = temp;
    }

    // cout << "after: " << after << endl;
    // cout << "before: " << before << endl;

    cout << after + 1 - before << endl;

    // cout << m_mktime(2011, 4, 21) << endl;
    // cout << m_mktime(2011, 4, 22) << endl;
}