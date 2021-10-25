// https://www.infoarena.ro/problema/distante

#include <fstream>
	
#define NMAX 50001
	
 
	
using namespace std;
	
 
	
ifstream f("distante.in");
	
ofstream g("distante.out");
	
 
	
int d[NMAX], i, n, m, a, b, c, nrquiz, s;
	
bool ok;
	
 
	
int main()
	
{
	
    f >> nrquiz;
	
 
	
    while (nrquiz)
	
    {
	
        nrquiz --;
	
 
	
        f >> n >> m >> s;
	
 
	
        for (i = 1; i <= n; ++ i)
	
            f >> d[i];
	
 
	
        ok = 1;
	
 
	
        for (i = 1; i <= m; ++ i)
	
        {
	
            f >> a >> b >> c;
	
            if (d[a] + c < d[b] || d[b] + c < d[a])
	
                ok = 0;
	
        }
	
 
	
        if (d[s]) ok = 0;
	
 
	
        if (ok) g << "DA\n";
	
        else
	
            g << "NU\n";
	
    }
	
    return 0;
	
}