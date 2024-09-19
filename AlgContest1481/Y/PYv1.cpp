// 问题 Y: 素数
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 10010;

// 素数表
bool table[MAX];

// 个数
int nums;

void find_prime(int n)
{
    table[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (table[i] == 1)
        {
            continue;
        }
        // nums++;
        for (int j = i + i; j <= n; j += i)
        {
            table[j] = 1;
        }
    }
    // 去掉 2、3
    // for (int i = 2;)

    // find nums
    // for (int i = 1; i <= n; i++) {
    // if (table[i] == 0 && i % 10 == 1) nums++;
    // }
}

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n)
    {
        memset(table, 0, sizeof(table));
        if (n <= 1)
        {
            cout << -1 << endl;
            continue;
        }

        find_prime(n);
        bool first = true;
        bool flag = false;
        for (int i = 2; i < n; i++)
        {
            if (i % 10 == 1 && table[i] == 0)
            {
                flag = true;
                if (first)
                {
                    first = false;
                    printf("%d", i);
                }
                else
                {
                    printf(" %d", i);
                }
            }
        }

        if (!flag)
        {
            cout << -1 << endl;
        }
    }

    return 0;
}