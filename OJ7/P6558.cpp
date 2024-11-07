#include <cstdio>

int main() {
    long long int z, s;
    scanf("%lld", &z);
    if (z % 2 == 0) s = z / 2;
    else s = ((z / 2) - z);
    printf("%lld", s);
}
