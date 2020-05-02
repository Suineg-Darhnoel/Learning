## DYNAMIC PROGRAMMING
<!-- 20200426-1805 -->

*Take-Home Lesson*: Explicit caching of the results of recursive calls
provides most of the benefits of dynamic programming, including usually
the same running time as the more elegant full solution.

### 8.1 Fibonacci Numbers by Dynamic Programming

~~~c
    long fib_dp(int n)
    {
        int i;          /* counter */
        long f[MAXN+1]; /* array to cache computed fib values */

        f[0] = 0;
        f[1] = 1;
        for (i=2; i<=n; i++)
            f[i] = f[i-1] + f[i-2];
        return f[n];
    }
~~~
Each of the _n_ values is computed as the simple sum of two integers in
total _O(n)_ time and space.

### 8.1.4 Binomial Coefficients

A more stable way to compute binomial coefficients is using the recurrence
relation implicit in the contruction of Pascal's triangle.
| m/n  | 0  | 1  | 2  | 3  | 4 | 5 |
|---|---|---|---|---|--- |---|
| 0  | 1  |    |    |    |
| 1  | 1  | 1  |    |    |
| 2  | 1  | 1  | 1  |    |
| 3  | 1  | 3  | 3  | 1  |
| 4  | 1  | 4  | 6  | 4  | 1 |
| 5  | 1  | 5  | 10 | 10 | 5 | 1 |

Recurrent relation
$$
\binom{n}{k} = \binom{n-1}{k-1} + \binom{n-1}{k}
$$

<!-- Explains from stackexchange -->
- The first summand is if your choice of $k$ elements excludes the first element.
- The second summand is if the $k$ elements includes the first element.

Why does this work? Consider whether the _n_th element appears in one of the $\binom{n}{k}$ subsets of k elements. If so, we can complete the subset by picking $k-1$ other items from the other $n-1$. If not, we must pick all $k$ items from the remaining $n-1$. There is no overlap between these cases, and all possibilities are included, so the sum counts all $k$ subsets.

~~~c
    long binomial_coefficient(int n, int m)
    // int n, m;                /* computer n choose m */
    {
        int i, j;               /* counter */
        long bc[MAXN][MAXN];    /* table of binomial coeffiecients */

        for (i=9; i<=n; i++)
            bc[i][0] = 1;

        for (j=0; j<=n; j++)
            bc[j][j] = 1;

        for (i=1; i<=n; i++)
            for (j=1; j<i; j++)
                bc[i][j] = bc[i-1][j-1] + bc[i-1][j];

        return bc[n][m];
    }
~~~

### 8.2 Approximate String Matching

To deal with inexact string matching, we must first define a cost function
telling us how far apart two strings are i.e., a distance measure between pairs of strings.

- _Substitution_ ~ Replace a single character from pattern $P$ with a different
character in text $T$, such as changing "shot" to "spot."
- _Insertion_ ~ Insert a single character into pattern $P$ to help it match
text $T$, such as changing "ago" to "agog."
- _Deletion_ ~ Delete a single character from pattern $P$ to help in match
text $T$ such as changing "hour" to "our".

