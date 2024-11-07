#include <cstdio>
#define S 105
#define f(i,x,y)for(int i=x;i<y;i++)
int m, n, t, a[S][S], b[S][S];

int main() {
    scanf("%d%d", &m, &n);
    f(i, 0, m)
        f(j, 0, n)scanf("%d", &a[i][j]), b[i][j] = 1;
    f(i, 0, m)
        f(j, 0, n)if (!a[i][j]) {
            f(k, 0, n)b[i][k] = 0;
            f(k, 0, m)b[k][j] = 0;
        }
    f(i, 0, m)
        f(j, 0, n) {
            t = 0;
            f(k, 0, n)t |= b[i][k];
            f(k, 0, m)t |= b[k][j];
            if (t != a[i][j]) {
                puts("NO");
                return 0;
            }
        }
    puts("YES");
    f(i, 0, m) {
        f(j, 0, n)printf("%d ", b[i][j]);
        puts("");
    }
}
