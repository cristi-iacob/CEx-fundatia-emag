// https://www.infoarena.ro/problema/ausoara

#include <fstream>
	
#include <algorithm>
	
#define NMAX 1005
	
 
	
using namespace std;
	
 
	
ifstream f("ausoara.in");
	
ofstream g("ausoara.out");
	
 
	
int i, n, m, v[NMAX], ans[NMAX], j, cnt = 0;
	
 
	
void interclasare()
	
{
	
    int curr[NMAX], cont = 0, x = 1, y = 1;
	
 
	
    while (x <= cnt && y <= n)
	
    {
	
        if (ans[x] == v[y])
	
        {
	
            curr[++ cont] = ans[x];
	
            x ++;
	
            y ++;
	
        }
	
        if (ans[x] < v[y])
	
            x ++;
	
        if (ans[x] > v[y])
	
            y ++;
	
    }
	
 
	
    cnt = cont;
	
 
	
    for (int i = 1; i <= cont; ++ i)
	
        ans[i] = curr[i];
	
}
	
 
	
int main()
	
{
	
    f >> m;
	
 
	
    f >> n;
	
 
	
    for (i = 1; i <= n; ++ i)
	
    {
	
        f >> v[i];
	
        ans[i] = v[i];
	
    }
	
 
	
    cnt = n;
	
 
	
    for (j = 2; j <= m; ++ j)
	
    {
	
        f >> n;
	
 
	
        for (i = 1; i <= n; ++ i)
	
            f >> v[i];
	
 
	
        interclasare();
	
    }
	
 
	
    g << cnt << " ";
	
 
	
    for (i = 1; i <= cnt; ++ i)
	
        g << ans[i] << " ";
	
 
	
    return 0;
	
}