#include<stdio.h>
#include<math.h>

int main() {
    int a[101] = {0}, b[101] = {1}, m, s, i, n;
    scanf("%d%d", &m, &s);
    if ((s == 0 && m != 1) || s > 9 * m) printf("-1 -1");
    else {
        for (n = s, i = 0; n > 9; n -= 9, i++) a[i] = 9;
        a[i] = n;
        for (n = s, i = m - 1; n > 9; i--, n -= 9) b[i] = 9;
        b[i] += n - 1;
        for (i = 0; i < m; i++) printf("%d", b[i]);
        printf(" ");
        for (i = 0; i < m; i++) printf("%d", a[i]);
    }
}
