// https://www.infoarena.ro/problema/nrcuv

#include <fstream>
	
#include <algorithm>
	
#define NMAX 1005
	
#define LMAX 150
	
#define mod 104659
	
 
	
using namespace std;
	
 
	
ifstream f("nrcuv.in");
	
ofstream g("nrcuv.out");
	
 
	
int i, n, mat[LMAX][LMAX], dp[NMAX][LMAX], j, k, m, ans = 0;
	
char a, b;
	
 
	
int main()
	
{
	
    f >> n >> m;
	
 
	
    for (i = 1; i <= m; ++ i)
	
    {
	
        f >> a >> b;
	
        mat[a][b] = mat[b][a] = 1;
	
    }
	
 
	
    for (i = 'a'; i <= 'z'; ++ i)
	
        dp[1][i] = 1;
	
 
	
    for (i = 2; i <= n; ++ i)
	
        for (j = 'a'; j <= 'z'; ++ j)
	
            for (k = 'a'; k <= 'z'; ++ k)
	
                if (mat[j][k] == 0)
	
                {
	
                    dp[i][k] += dp[i - 1][j];
	
                    dp[i][k] %= mod;
	
                }
	
 
	
    for (i = 'a'; i <= 'z'; ++ i)
	
    {
	
        ans += dp[n][i];
	
        ans %= mod;
	
    }
	
 
	
    g << ans << '\n';
	
    return 0;
	
}