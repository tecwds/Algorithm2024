#include<iostream>
#define f(i,a,b)for(i=a;i<=b;i++)
long long Y[505][505], Z[505], I[3], N, M, X, i, j;
using namespace std;

int main() {
    cin >> N >> M >> X;
    f(i, 1, M) {
        string s;
        cin >> s;
        f(j, 0, N-1)Z[j] += s[j] - '0';
    }
    f(i, 0, N-1)I[Z[i]]++;
    Y[I[0]][I[1]] = 1;
    for (i = N; i >= 0; i--)
        for (j = N; j >= 0; j--) {
            if (i > 1)Y[i - 2][j + 2] = (Y[i - 2][j + 2] + Y[i][j] * i * (i - 1) / 2) % X;
            if (i > 0 && j > 0)Y[i - 1][j] = (Y[i - 1][j] + Y[i][j] * i * j) % X;
            if (j > 1)Y[i][j - 2] = (Y[i][j - 2] + Y[i][j] * j * (j - 1) / 2) % X;
        }
    cout << Y[0][0];

    return 0;
}
