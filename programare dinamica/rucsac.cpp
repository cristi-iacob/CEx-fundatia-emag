// https://www.infoarena.ro/problema/rucsac

#include <fstream>
	
#include <algorithm>
	
#define NMAX 5005
	
 
	
using namespace std;
	
 
	
ifstream f("rucsac.in");
	
ofstream g("rucsac.out");
	
 
	
int i, j, n, G, gr, dp[2][2 * NMAX], pr;
	
 
	
int main()
	
{
	
    f >> n >> G;
	
 
	
    for (i = 1; i <= n; ++ i)
	
    {
	
        f >> gr >> pr;
	
 
	
        for (j = 0; j <= G; ++ j)
	
        {
	
            dp[i % 2][j] = dp[(i + 1) % 2][j];
	
 
	
            if (j - gr >= 0)
	
                dp[i % 2][j] = max(dp[i % 2][j], dp[(i + 1) % 2][j - gr] + pr);
	
        }
	
    }
	
 
	
    g << dp[n % 2][G] << '\n';
	
 
	
    return 0;
	
}