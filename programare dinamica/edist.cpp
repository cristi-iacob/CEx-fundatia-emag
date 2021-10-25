// https://www.infoarena.ro/problema/edist

#include <fstream>
	
#include <algorithm>
	
#include <cstring>
	
#define NMAX 20005
	
 
	
using namespace std;
	
 
	
ifstream f("edist.in");
	
ofstream g("edist.out");
	
 
	
int i, n, m, k, j, dp[2][NMAX];
	
char a[NMAX], b[NMAX];
	
 
	
int main()
	
{
	
    f >> n >> m >> k;
	
 
	
    for (i = 1; i <= n; ++ i)
	
        f >> a[i];
	
 
	
    for (i = 1; i <= m; ++ i)
	
        f >> b[i];
	
 
	
  //  for (i = 1; i <= max(n, m); ++ i)
	
    //    dp[i][0] = dp[0][i] = i;
	
 
	
    for (i = 1; i <= n; ++ i)
	
        for (j = max(1, i - k); j <= min(i + k, m); ++ j)
	
            if (min(i, j) == 1)
	
                dp[i % 2][j] = max(i, j);
	
            else
	
                dp[i % 2][j] = min(min(dp[(i + 1) % 2][j] + 1, dp[i % 2][j - 1] + 1), dp[(i + 1) % 2][j - 1] + !(a[i] == b[j]));
	
 
	
    g << dp[n % 2][m] - 1 << '\n';
	
 
	
    return 0;
	
}