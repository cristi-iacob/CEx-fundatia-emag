// https://www.infoarena.ro/problema/bleach

#include <fstream>
	
#include <vector>
	
#include <queue>
	
#define NMAX 1000005
	
#define inf 2000000000
	
 
	
using namespace std;
	
 
	
ifstream f("bleach.in");
	
ofstream g("bleach.out");
	
 
	
int i, n, k, x, v[NMAX], cont = 0;
	
long long ans, p = 0;
	
 
	
struct compare
	
{
	
    bool operator () (int &a, int &b)
	
    {
	
        return a > b;
	
    }
	
};
	
 
	
priority_queue < int, vector < int >, compare > pq;
	
 
	
int main()
	
{
	
    f >> n >> k;
	
 
	
    for (i = 1; i <= k + 1; ++ i)
	
    {
	
        f >> x;
	
        pq.push(x);
	
    }
	
 
	
    for (i = k + 2; i <= n; ++ i)
	
    {
	
        int curr = pq.top();
	
        pq.pop();
	
 
	
        if (p >= curr)
	
            p += curr;
	
        else
	
        {
	
            ans += curr - p;
	
            p = 2 * curr;
	
        }
	
 
	
        f >> x;
	
        pq.push(x);
	
    }
	
 
	
    while (!pq.empty())
	
    {
	
        int curr = pq.top();
	
        pq.pop();
	
 
	
        if (p >= curr)
	
            p += curr;
	
        else
	
        {
	
            ans += curr - p;
	
            p = 2 * curr;
	
        }
	
    }
	
 
	
    g << ans << '\n';
	
    return 0;
	
}