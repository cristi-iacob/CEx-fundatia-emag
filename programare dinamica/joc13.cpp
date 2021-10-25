// https://www.infoarena.ro/problema/joc13

#include <fstream>
	
#include <algorithm>
	
#define NMAX 50005
	
#define inf 2000000000
	
 
	
using namespace std;
	
 
	
ifstream f("joc13.in");
	
ofstream g("joc13.out");
	
 
	
int mat[3][NMAX], dp[3][NMAX], i, j, k, n, sp, l;
	
 
	
int main()
	
{
	
    f >> n >> k;
	
 
	
    for (i = 1; i <= 2; ++ i)
	
        for (j = 1; j <= n; ++ j)
	
            f >> mat[i][j];
	
 
	
    dp[1][1] = mat[1][1];
	
    dp[2][1] = 0;
	
 
	
    for (i = 2; i <= n; ++ i)
	
        for (j = 1; j <= 2; ++ j)
	
    {
	
        int curr = -inf;
	
        sp = mat[j][i];
	
 
	
        for (l = 1; l < k && l < i; ++ l)
	
        {
	
            sp += mat[j][i - l];
	
            curr = max(curr, sp + dp[(j % 2) + 1][i - l]);
	
        }
	
        dp[j][i] = curr;
	
    }
	
 
	
    dp[2][n] = max(dp[2][n], dp[1][n] + mat[2][n]);
	
 
	
    g << dp[2][n] << '\n';
	
    return 0;
	
}