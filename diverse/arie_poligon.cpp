// https://www.infoarena.ro/problema/aria

#include <fstream>
	
#include <cmath>
	
#include <iomanip>
	
 
	
using namespace std;
	
 
	
ifstream f("aria.in");
	
ofstream g("aria.out");
	
 
	
struct arie
	
{
	
    double x, y;
	
};
	
arie v[100001];
	
 
	
int i,n;
	
double s=0;
	
 
	
int main()
	
{
	
    f>>n;
	
    for (i=1; i<=n; ++i)
	
    f>>v[i].x>>v[i].y;
	
 
	
    v[n+1]=v[1];
	
 
	
    for (i=1; i<=n; ++i)
	
    s+=(v[i].x*v[i+1].y-v[i+1].x*v[i].y);
	
 
	
    g<<fixed<<setprecision(5)<<abs(s/2);
	
 
	
    return 0;
	
}