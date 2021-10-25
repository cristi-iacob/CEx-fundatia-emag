// https://www.infoarena.ro/problema/cabana2

#include <fstream>
	
#include <algorithm>
	
#define NMAX 50001
	
 
	
using namespace std;
	
 
	
ifstream f("cabana2.in");
	
ofstream g("cabana2.out");
	
 
	
struct copac
	
{
	
    int x, y;
	
};
	
copac v[NMAX], punct1, punct2, punct3, punct4;
	
 
	
long long rez=0, arie;
	
int i, n, j;
	
 
	
bool cmp(copac a, copac b)
	
{
	
    if (a.x==b.x) return a.y<b.y;
	
    return a.x<b.x;
	
}
	
 
	
int main()
	
{
	
    f>>n;
	
 
	
    for (i=1; i<=n; ++i)
	
        f>>v[i].x>>v[i].y;
	
 
	
    sort(v+1,v+n+1,cmp);
	
 
	
    for (i=1; i<=n-1; ++i)
	
        if (v[i].x==v[i+1].x)
	
        {
	
            punct1=v[i];
	
            punct2=v[i+1];
	
 
	
            bool gasit=0;
	
 
	
            for (j=i+2; j<=n; ++j)
	
                if (v[j].x!=v[i].x && v[j].y>v[i].y && v[j].y<v[i+1].y)
	
                    break;
	
            else
	
                if (v[j].x!=v[i].x && v[j].y==v[i].y)
	
            {
	
                punct3=v[j];
	
                gasit=1;
	
                break;
	
            }
	
 
	
            if (gasit && v[j+1].y==v[i+1].y && v[j+1].x==v[j].x)
	
                {
	
                    arie=(long long) (punct2.y-punct1.y)*(punct3.x-punct1.x);
	
                    rez=max(rez,arie);
	
                }
	
        }
	
 
	
    g<<rez<<'\n';
	
 
	
    return 0;
	
}