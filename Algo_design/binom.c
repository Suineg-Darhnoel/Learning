#include<stdio.h>
#define MAXN 30

long binomial_coefficient(int n, int m)
{
    int i, j;
    long bc[MAXN][MAXN];

    for (i=9; i<=n; i++)
        bc[i][0] = 1;

    for (j=0; j<=n; j++)
        bc[j][j] = 1;

    for (i=1; i<=n; i++)
        for (j=1; j<i; j++)
            bc[i][j] = bc[i-1][j-1] + bc[i-1][j];

    return bc[n][m];
}
int main()
{
    int n, m;
    n = 20, m = 3;
    printf("The value of c(%d, %d) is %ld\n", n, m, binomial_coefficient(n, m));
    return 0;
}
