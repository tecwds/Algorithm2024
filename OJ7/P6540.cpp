#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
#define gg 10.0
#define N 1005
#define eps (1e-6)
#define ll int
double p[N];
ll n;

void input() {
    for (ll i = 1; i <= n; i++)cin >> p[i];
}

double ok(double x) {
    double now = x;
    double siz = 0;
    for (ll i = 1; i <= n; i++) {
        siz += floor(now / gg);
        now -= floor(now / gg) * gg;
        if (siz != p[i]) {
            double cha = (p[i] - siz) * 10.0 - now;
            now = 0;
            x += cha / i;
        }
        siz = p[i];
        now += x;
    }
    return now;
}

double ok2(double x) {
    double now = x;
    double siz = 0;
    for (ll i = 1; i <= n; i++) {
        siz += floor(now / gg);
        now -= floor(now / gg) * gg;
        if (siz != p[i]) {
            double cha = (siz - p[i]) * 10.0 - (10.0 - now - eps);
            now = 10.0 - eps;
            x -= cha / i;
        }
        siz = p[i];
        now += x;
    }
    return now;
}

int main() {
    ll i, j;
    while (cin >> n) {
        input();
        double l = ok(p[1] * 10.0) + eps;
        double r = ok2(p[1] * 10.0 + 10.0);
        l = floor(l / 10.0);
        r = floor(r / 10.0);
        if (l == r) {
            puts("unique");
            printf("%.0lf\n", p[n] + l);
        } else puts("not unique");
    }
    return 0;
}
