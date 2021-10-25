// https://www.infoarena.ro/problema/rmq

#include <fstream>
	
#include <cmath>
	
#include <algorithm>
	
#define NMAX 100005
	
#define LMAX 18
	
 
	
using namespace std;
	
 
	
ifstream f("rmq.in");
	
ofstream g("rmq.out");
	
 
	
int i, n, nrquiz, x, y, v[NMAX], rmq[NMAX][LMAX], j;
	
 
	
int main()
	
{
	
    f >> n >> nrquiz;
	
 
	
    for (i = 1; i <= n; ++ i)
	
    {
	
        f >> v[i];
	
        rmq[i][0] = i;
	
    }
	
 
	
    for (j = 1; (1 << j) <= n; ++ j)
	
        for (i = 1; i + (1 << j) - 1 <= n; ++ i)
	
            if (v[rmq[i][j - 1]] < v[rmq[i + (1 << (j - 1))][j - 1]])
	
                rmq[i][j] = rmq[i][j - 1];
	
            else
	
                rmq[i][j] = rmq[i + (1 << (j - 1))][j - 1];
	
 
	
    for (; nrquiz; -- nrquiz)
	
    {
	
        f >> x >> y;
	
 
	
        int l = log2(y - x + 1);
	
 
	
        if (v[rmq[x][l]] < v[rmq[y - (1 << l) + 1][l]])
	
            g << v[rmq[x][l]] << '\n';
	
        else
	
            g << v[rmq[y - (1 << l) + 1][l]] << '\n';
	
    }
	
    return 0;
	
}