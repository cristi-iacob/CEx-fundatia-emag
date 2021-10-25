// https://infoarena.ro/problema/maxflow

#include <fstream>
	
#include <vector>
	
#include <queue>
	
#include <algorithm>
	
#define NMAX 1005
	
#define inf 2000000000
	
 
	
using namespace std;
	
 
	
ifstream f("maxflow.in");
	
ofstream g("maxflow.out");
	
 
	
int i, n, m, x, y, z, cost[NMAX][NMAX], flow[NMAX][NMAX], father[NMAX], ans = 0;
	
vector < int > v[NMAX];
	
bool visited[NMAX];
	
queue < int > q;
	
 
	
bool BFS()
	
{
	
    for (i = 1; i <= n; ++ i)
	
        visited[i] = 0;
	
 
	
    q.push(1);
	
    visited[1] = 1;
	
 
	
    while (!q.empty())
	
    {
	
        int curr = q.front();
	
        q.pop();
	
 
	
        if (curr == n)
	
            continue;
	
 
	
        for (auto & it : v[curr])
	
            if (!visited[it] && cost[curr][it] != flow[curr][it])
	
        {
	
            q.push(it);
	
            visited[it] = 1;
	
            father[it] = curr;
	
        }
	
    }
	
 
	
    return visited[n];
	
}
	
 
	
int main()
	
{
	
    f >> n >> m;
	
 
	
    for (i = 1; i <= m; ++ i)
	
    {
	
        f >> x >> y >> z;
	
        v[x].push_back(y);
	
        v[y].push_back(x);
	
        cost[x][y] = z;
	
    }
	
 
	
    while (BFS())
	
    {
	
        for (auto & it : v[n])
	
        {
	
            if (!visited[it] || cost[it][n] == flow[it][n])
	
                continue;
	
 
	
            int curr = n;
	
            father[n] = it;
	
            int minflow = inf;
	
 
	
            while (curr != 1)
	
            {
	
                minflow = min(minflow, cost[father[curr]][curr] - flow[father[curr]][curr]);
	
                curr = father[curr];
	
            }
	
 
	
            if (minflow == 0)
	
                continue;
	
 
	
            curr = n;
	
 
	
            while (curr != 1)
	
            {
	
                flow[father[curr]][curr] += minflow;
	
                flow[curr][father[curr]] -= minflow;
	
                curr = father[curr];
	
            }
	
 
	
            ans += minflow;
	
        }
	
    }
	
 
	
    g << ans << '\n';
	
    return 0;
	
}