// https://www.infoarena.ro/problema/armonica

#include <fstream>
	
#include <vector>
	
#include <set>
	
 
	
using namespace std;
	
 
	
ifstream f("armonica.in");
	
ofstream g("armonica.out");
	
 
	
long long b, p;
	
int i, n, j;
	
vector < long long > divi;
	
set < pair < long long, long long > > ans;
	
 
	
int main()
	
{
	
    f >> b;
	
 
	
    for (int d = 1; d * d <= b; ++ d)
	
        if (b % d == 0)
	
        {
	
            divi.push_back(d);
	
            if (1LL * d * d != b)
	
                divi.push_back(b / d);
	
        }
	
 
	
    n = divi.size();
	
 
	
    for (i = 0; i < n; ++ i)
	
        for (j = i; j < n; ++ j)
	
    {
	
        p = 1LL * divi[i] * divi[j];
	
 
	
        long long a = (b + p) / 2;
	
        long long c = a * b / (divi[i] * divi[j]);
	
 
	
        if (a * b == c * (2 * a - b))
	
            ans.insert({a, c}), ans.insert({c, a});
	
    }
	
 
	
    g << ans.size() << '\n';
	
 
	
    for (auto & it : ans)
	
        g << it.first << " " << it.second << '\n';
	
 
	
    return 0;
	
 
	
}