// https://www.infoarena.ro/problema/cautbin

#include <fstream>
	
#include <vector>
	
#include <algorithm>
	
#define NMAX 100005
	
 
	
using namespace std;
	
 
	
ifstream f("cautbin.in");
	
ofstream g("cautbin.out");
	
 
	
int n, v[NMAX], nrquiz, type, val, ans;
	
 
	
int main()
	
{
	
    f >> n;
	
 
	
    for (int i = 1; i <= n; ++ i)
	
        f >> v[i];
	
 
	
    f >> nrquiz;
	
 
	
    while (nrquiz)
	
    {
	
        nrquiz --;
	
 
	
        f >> type >> val;
	
 
	
        if (type == 0)
	
        {
	
            ans = upper_bound(v + 1, v + n + 1, val) - v - 1;
	
            if (!(ans >= 1 && ans <= n && v[ans] == val))
	
                ans = -1;
	
        }
	
            else
	
                if (type == 1)
	
            {
	
                ans = upper_bound(v + 1, v + n + 1, val) - v - 1;
	
            }
	
            else
	
                if (type == 2)
	
            {
	
                ans = lower_bound(v + 1, v + n + 1, val) - v;
	
            }
	
        g << ans << '\n';
	
    }
	
    return 0;
	
}