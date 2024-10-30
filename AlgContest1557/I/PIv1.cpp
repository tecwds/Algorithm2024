//
// Created by wpan on 10/30/24.
//
#include<iostream>
#include<string>
using namespace std;
int pan[12][12];

int main() {
    int sum = 0;
    for (auto & i : pan)
        for (int & j : i) j = 0;

    for (int i = 0; i < 12; i++) {
        pan[i][0] = -1;
        pan[0][i] = -1;
        pan[i][11] = -1;
        pan[11][i] = -1;
    }
    for (int i = 1; i < 11; i++)
        for (int j = 1; j < 11; j++) {
            cin >> pan[i][j];
        }

    for (int i = 1; i < 11; i++)
        for (int j = 1; j < 11; j++) {
            if (pan[i][j] == 0 && pan[i - 1][j] == -1)
                pan[i][j] = -1;
            if (pan[i][j] == 0 && pan[i][j - 1] == -1)
                pan[i][j] = -1;
            if (pan[i][j] == 0 && pan[i + 1][j] == -1)
                pan[i][j] = -1;
            if (pan[i][j] == 0 && pan[i][j + 1] == -1)
                pan[i][j] = -1;
        }
    for (int j = 1; j < 11; j++)
        for (int i = 1; i < 11; i++) {
            if (pan[i][j] == 0 && pan[i - 1][j] == -1)
                pan[i][j] = -1;
            if (pan[i][j] == 0 && pan[i][j - 1] == -1)
                pan[i][j] = -1;
            if (pan[i][j] == 0 && pan[i + 1][j] == -1)
                pan[i][j] = -1;
            if (pan[i][j] == 0 && pan[i][j + 1] == -1)
                pan[i][j] = -1;
        }
    for (int i = 1; i < 11; i++)
        for (int j = 1; j < 11; j++) {
            if (pan[i][j] == 0)
                sum++;
        }
    cout << sum;
}
