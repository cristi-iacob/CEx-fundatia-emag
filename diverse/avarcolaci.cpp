// https://www.infoarena.ro/problema/avarcolaci

#include <fstream>
	
#include <algorithm>
	
#define NMAX 20
	
 
	
using namespace std;
	
 
	
ifstream f("avarcolaci.in");
	
ofstream g("avarcolaci.out");
	
 
	
int t, i, n, nr, cont, current, best[NMAX], j;
	
 
	
int main()
	
{
	
    f >> t;
	
 
	
    for (j = 1; j <= t; ++ j)
	
    {
	
        f >> n;
	
        cont = 0;
	
 
	
        for (i = 1; i <= 2 * n; ++ i)
	
        {
	
            f >> nr;
	
 
	
            if (cont == 0)
	
            {
	
                current = nr;
	
                cont ++;
	
            }
	
            else
	
                if (nr == current)
	
                    cont ++;
	
            else
	
                    cont --;
	
        }
	
 
	
        best[j] = current;
	
    }
	
 
	
    f.close();
	
 
	
    ifstream fin("avarcolaci.in");
	
 
	
    fin >> t;
	
 
	
    for (j = 1; j <= t; ++ j)
	
    {
	
        fin >> n;
	
        cont = 0;
	
 
	
        for (i = 1; i <= 2 * n; ++ i)
	
        {
	
            fin >> nr;
	
            if (best[j] == nr)
	
                cont ++;
	
        }
	
 
	
        if (cont >= n + 1)
	
            g << best[j] << '\n';
	
        else
	
            g << "Mozart" << '\n';
	
    }
	
    return 0;
	
}