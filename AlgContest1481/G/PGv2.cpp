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

    for (int i = 1; i < year; i++) {
        if ( //判断闰年
             i % 4 == 0 &&
            (i % 100 != 0 || i % 400 == 0)
        ) {
            mk += 366;
        } else {
            mk += 365;
        }
    }

    // 月份
    int m_day[] = {
        0, // m_day[0] = 0
        31, 28,
        31, 30,
        31, 30,
        31, 31,
        30, 31,
        30, 31
    };

    // 当前年是否是闰年，是则修改月份数据中的2月数据
    if (year % 4 == 0 &&(year % 100 != 0 || year % 400 == 0)) {
        m_day[2] = 29;
    }

    for (int i = 1; i < mon; i++) {
        mk += m_day[i];
    }

    // 日
    mk += day;
    return mk;
}

int main()
{
    cin >> date_b >> date_a;

    long long before = m_mktime(stoi(date_b.substr(0,4)), stoi(date_b.substr(4, 2)), stoi(date_b.substr(6,2)));
    long long after = m_mktime(stoi(date_a.substr(0,4)), stoi(date_a.substr(4, 2)), stoi(date_a.substr(6,2)));

    long long temp = 0;

    // 缝缝补补
    if (before > after) {
        temp = before;
        before = after;
        after = temp;
    }

    cout << after + 1 - before << endl;
}