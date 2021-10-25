// https://www.infoarena.ro/problema/suma4

#include <fstream>
	
#define NMAX 60
	
#define inf 2000000000
	
 
	
using namespace std;
	
 
	
ifstream f("suma4.in");
	
ofstream g("suma4.out");
	
 
	
int i, n, x, m, dp[NMAX][NMAX][NMAX], j, k, mat[NMAX][NMAX][NMAX], ans = inf, y;
	
 
	
int transf(int x, int y, int k)
	
{
	
    return k * (k - 1) * (2 * k - 1) / 6 + (x - 1) * k + y;
	
}
	
 
	
void afisare(int x, int y, int niv)
	
{
	
    if (niv == 1)
	
        g << 1 << " ";
	
    else
	
    if (dp[x - 1][y - 1][niv - 1] == dp[x][y][niv] - mat[x][y][niv])
	
    {
	
        afisare(x - 1, y - 1, niv - 1);
	
        g << transf(x, y, niv) << " ";
	
    }
	
    else
	
        if (dp[x - 1][y][niv - 1] == dp[x][y][niv] - mat[x][y][niv])
	
    {
	
        afisare(x - 1, y, niv - 1);
	
        g << transf(x, y, niv) << " ";
	
    }
	
    else
	
        if (dp[x][y - 1][niv - 1] == dp[x][y][niv] - mat[x][y][niv])
	
    {
	
        afisare(x, y - 1, niv - 1);
	
        g << transf(x, y, niv) << " ";
	
    }
	
    else
	
        if (dp[x][y][niv - 1] == dp[x][y][niv] - mat[x][y][niv])
	
    {
	
        afisare(x, y, niv - 1);
	
        g << transf(x, y, niv) << " ";
	
    }
	
}
	
 
	
int main()
	
{
	
    f >> n;
	
 
	
    int s = 0;
	
 
	
    for (i = 1; i <= n; ++ i)
	
    {
	
        s += i * i;
	
 
	
        if (s == n)
	
            break;
	
    }
	
 
	
    m = i;
	
 
	
    g << m << " ";
	
 
	
    for (i = 1; i <= m; ++ i)
	
        for (j = 1; j <= i; ++ j)
	
            for (k = 1; k <= i; ++ k)
	
                f >> mat[j][k][i];
	
 
	
    for (k = 0; k <= m + 1; ++ k)
	
        for (i = 0; i <= m + 1; ++ i)
	
            for (j = 0; j <= m + 1; ++ j)
	
                dp[i][j][k] = inf;
	
 
	
    dp[1][1][1] = mat[1][1][1];
	
 
	
    for (k = 2; k <= m; ++ k)
	
        for (i = 1; i <= k; ++ i)
	
            for (j = 1; j <= k; ++ j)
	
                dp[i][j][k] = min(min(min(dp[i][j][k - 1], dp[i - 1][j][k - 1]), dp[i][j - 1][k - 1]), dp[i - 1][j - 1][k - 1]) + mat[i][j][k];
	
 
	
    for (i = 1; i <= m; ++ i)
	
        for (j = 1; j <= m; ++ j)
	
            ans = min(ans, dp[i][j][m]);
	
 
	
    for (i = 1; i <= m; ++ i)
	
        for (j = 1; j <= m; ++ j)
	
            if (dp[i][j][m] == ans)
	
    {
	
        x = i;
	
        y = j;
	
        i = m + 1;
	
        j = m + 1;
	
    }
	
 
	
    g << ans << '\n';
	
 
	
    afisare(x, y, m);
	
    return 0;
	
}