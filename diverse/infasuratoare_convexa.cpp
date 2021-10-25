// https://www.infoarena.ro/problema/infasuratoare

#include <fstream>
	
#include <algorithm>
	
#include <cmath>
	
#include <iomanip>
	
#define NMAX 120005
	
 
	
using namespace std;
	
 
	
ifstream f("infasuratoare.in");
	
ofstream g("infasuratoare.out");
	
 
	
int i, n, ans = 0;
	
 
	
struct punct
	
{
	
    double x, y;
	
};
	
punct v[NMAX], stiva[NMAX];
	
 
	
double det(punct a, punct b, punct c)
	
{
	
    return a.x * b.y + b.x * c.y + c.x * a.y - c.x * b.y - b.x * a.y - a.x * c.y;
	
}
	
 
	
bool cmp1(punct a, punct b)
	
{
	
    if (a.x == b.x)
	
        return a.y < b.y;
	
    return a.x < b.x;
	
}
	
 
	
bool cmp2(punct a, punct b)
	
{
	
    return det(v[1], a, b) < 0;
	
}
	
 
	
int main()
	
{
	
    f >> n;
	
 
	
    for (i = 1; i <= n; ++ i)
	
        f >> v[i].x >> v[i].y;
	
 
	
    sort(v + 1, v + n + 1, cmp1);
	
    sort(v + 2, v + n + 1, cmp2);
	
 
	
    ans = 3;
	
    stiva[1] = v[1];
	
    stiva[2] = v[2];
	
    stiva[3] = v[3];
	
 
	
    for (i = 4; i <= n; ++ i)
	
    {
	
        while (ans >= 3 && det(stiva[ans], stiva[ans - 1], v[i]) < 0)
	
            ans --;
	
        stiva[++ ans] = v[i];
	
    }
	
 
	
    g << ans << '\n';
	
 
	
    g << fixed << setprecision(12);
	
    for (i = ans; i >= 1; -- i)
	
        g << stiva[i].x << " " << stiva[i].y << '\n';
	
    return 0;
	
}