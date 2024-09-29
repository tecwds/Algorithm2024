//
// Created by wpan on 24-9-29.
//
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;

    int n;
    int m;

    cin >> n >> m;

    vector<pair<int, int> > road(n);
    vector<pair<int, int> > bessy(m);

    // 读取道路信息
    for (int i = 0; i < n; ++i)
        cin >> road[i].second >> road[i].first;

    // 读取贝西的旅程信息
    for (int i = 0; i < m; ++i)
        cin >> bessy[i].second >> bessy[i].first;

    // 最大超速值
    int max_over_speed = 0;

    int current_road = 0;

    // 剩余道路长度
    int less_road_len = road[0].second;

    // 遍历贝西的旅程
    for (const auto&[fst, snd]: bessy) {
        const int speed = fst;
        int length = snd;

        while (length > 0) {
            const int speed_limit = road[current_road].first;

            if (const int over_speed = speed - speed_limit; over_speed > max_over_speed)
                max_over_speed = over_speed;

            if (length >= less_road_len) {
                length -= less_road_len;
                current_road++;
                if (current_road < n) {
                    less_road_len = road[current_road].second;
                }
            } else {
                less_road_len -= length;
                length = 0;
            }
        }
    }

    cout << max_over_speed << endl;

    return 0;
}
