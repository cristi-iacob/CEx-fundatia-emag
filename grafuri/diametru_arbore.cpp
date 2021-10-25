// https://infoarena.ro/problema/darb

#include <fstream>
	
#include <vector>
	
#include <queue>
	
#define NMAX 100005
	
#define inf 2000000000
	
 
	
using namespace std;
	
 
	
ifstream f("darb.in");
	
ofstream g("darb.out");
	
 
	
int i, n, x, y, d[NMAX], start, maxim = -1, ans = -1;
	
vector < int > v[NMAX];
	
queue < int > q;
	
 
	
void BFS(int node)
	
{
	
    q.push(node);
	
 
	
    while (!q.empty())
	
    {
	
        int curr = q.front();
	
        q.pop();
	
 
	
        for (auto & it : v[curr])
	
            if (d[it] > d[curr] + 1)
	
        {
	
            d[it] = d[curr] + 1;
	
            q.push(it);
	
        }
	
    }
	
}
	
 
	
int main()
	
{
	
    f >> n;
	
 
	
    for (i = 1; i <= n - 1; ++ i)
	
    {
	
        f >> x >> y;
	
        v[x].push_back(y);
	
        v[y].push_back(x);
	
    }
	
 
	
    for (i = 2; i <= n; ++ i)
	
        d[i] = inf;
	
 
	
    BFS(1);
	
 
	
    for (i = 1; i <= n; ++ i)
	
        if (d[i] > maxim)
	
    {
	
        maxim = d[i];
	
        start = i;
	
    }
	
 
	
    for (i = 1; i <= n; ++ i)
	
        d[i] = inf;
	
    d[start] = 0;
	
 
	
    BFS(start);
	
 
	
    for (i = 1; i <= n; ++ i)
	
        ans = max(ans, d[i]);
	
 
	
    g << ans + 1 << '\n';
	
    return 0;
	
}