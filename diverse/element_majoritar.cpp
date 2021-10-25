// https://www.infoarena.ro/problema/elmaj

#include <fstream>
	
 
	
using namespace std;
	
ifstream f("elmaj.in");
	
ofstream g("elmaj.out");
	
int i,n,v[1000005],el,cont=0,cont1=0;
	
int main()
	
{
	
    f>>n;
	
    for (i=1; i<=n; i++)
	
    {
	
        f>>v[i];
	
        if (cont==0)
	
            el=v[i];
	
        if (v[i]==el)
	
            cont++;
	
        else
	
            cont--;
	
    }
	
    for (i=1; i<=n; i++)
	
        if (v[i]==el) cont1++;
	
    if (cont1>=n/2+1) g<<el<<" "<<cont1;
	
    else
	
        g<<"-1";
	
 
	
    return 0;
	
}