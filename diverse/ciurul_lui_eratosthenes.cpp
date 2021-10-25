// https://www.infoarena.ro/problema/ciur

#include <fstream>
	
#include <bitset>
	
#include <vector>
	
#define NMAX 2000050
	
 
	
using namespace std;
	
 
	
ifstream f("ciur.in");
	
ofstream g("ciur.out");
	
 
	
bitset < NMAX > v;
	
int n;
	
 
	
int ciur()
	
{
	
    v[0] = v[1] = 1;
	
    int ans = 1;
	
 
	
    for (int i = 4; i <= n; i += 2)
	
        v[i] = 1;
	
 
	
    for (int i = 3; i <= n; i += 2)
	
        if (v[i] == 0)
	
        {
	
            ans ++;
	
            for (int j = 3 * i; j <= n; j += i)
	
                v[j] = 1;
	
        }
	
    return ans;
	
}
	
 
	
int main()
	
{
	
    f >> n;
	
    g << ciur() << '\n';
	
    return 0;
	
}