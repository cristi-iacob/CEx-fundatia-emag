// https://www.infoarena.ro/problema/strmatch

#include <fstream>
	
#include <cstring>
	
#include <algorithm>
	
#define NMAX 2000005
	
 
	
using namespace std;
	
 
	
ifstream f("strmatch.in");
	
ofstream g("strmatch.out");
	
 
	
int i, n, m, k = 0, pi[NMAX], cnt = 0, ans[NMAX];
	
char a[NMAX], b[NMAX];
	
 
	
int main()
	
{
	
    f.getline(a + 1, NMAX - 3);
	
    f.getline(b + 1, NMAX - 3);
	
    n = strlen(a + 1);
	
    m = strlen(b + 1);
	
 
	
    for (i = 2; i <= n; ++ i)
	
    {
	
        while (k > 0 && a[i] != a[k + 1])
	
            k = pi[k];
	
 
	
        if (a[i] == a[k + 1])
	
            k ++;
	
 
	
        pi[i] = k;
	
    }
	
 
	
    k = 0;
	
 
	
    for (i = 1; i <= m; ++ i)
	
    {
	
        while (k > 0 && b[i] != a[k + 1])
	
            k = pi[k];
	
 
	
        if (b[i] == a[k + 1])
	
            k ++;
	
 
	
        if (k == n)
	
        {
	
            cnt ++;
	
 
	
            if (cnt <= 1000)
	
               ans[cnt] = i - n;
	
 
	
            k = pi[k];
	
        }
	
    }
	
 
	
    g << cnt << '\n';
	
 
	
    for (i = 1; i <= min(1000, cnt); ++ i)
	
        g << ans[i] << " ";
	
    return 0;
	
}