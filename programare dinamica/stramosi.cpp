// https://www.infoarena.ro/problema/stramosi

#include <fstream>
	
#include <cmath>
	
#define NMAX 250005
	
#define LMAX 22
	
 
	
using namespace std;
	
 
	
ifstream f("stramosi.in");
	
ofstream g("stramosi.out");
	
 
	
int n, nrq, x, y, tata[NMAX], dp[LMAX][NMAX], lg[NMAX];
	
 
	
int main()
	
{
	
    f >> n >> nrq;
	
 
	
    lg[0] = -1;
	
 
	
    for (int i = 1; i <= n; ++ i)
	
    {
	
        f >> tata[i];
	
        lg[i] = lg[i / 2] + 1;
	
        dp[0][i] = tata[i];
	
    }
	
 
	
    for (int i = 1; (1 << i) <= n; ++ i)
	
        for (int j = 1; j <= n; ++ j)
	
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
	
 
	
    while (nrq)
	
    {
	
        nrq --;
	
 
	
        f >> x >> y;
	
 
	
        while (y)
	
        {
	
            x = dp[lg[y]][x];
	
            y -= (1 << lg[y]);
	
        }
	
 
	
        g << x << '\n';
	
    }
	
    return 0;
	
}