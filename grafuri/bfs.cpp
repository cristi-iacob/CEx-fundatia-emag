// https://infoarena.ro/problema/bfs

#include <fstream>	
#include <vector>	
#include <algorithm>	
#include <queue>	
#define NMAX 100005	
#define inf 2000000000
 
using namespace std;
 	
ifstream f("bfs.in");	
ofstream g("bfs.out");	
 	
int i, n, m, start, d[NMAX], x, y;	
vector < int > v[NMAX];	
bool visited[NMAX];	
queue < int > q;	
 	
void BFS()	
{	
    q.push(start);	
    visited[NMAX] = 1;	
 	
    while (!q.empty())	
    {	
        int curr = q.front();	
        q.pop();	
	
        for (auto & it : v[curr])	
            if (!visited[it])	
        {	
            d[it] = min(d[it], d[curr] + 1);	
            q.push(it);	
            visited[it] = 1;	
        }	
    }	
}	
 	
int main()	
{	
    f >> n >> m >> start;	
 	
    for (i = 1; i <= m; ++ i)	
    {	
        f >> x >> y;
        v[x].push_back(y);	
    }	
 	
    for (i = 1; i <= n; ++ i)	
        d[i] = inf;	
    d[start] = 0;	
 	
    BFS();
 	
    for (i = 1; i <= n; ++ i)
	    if (d[i] == inf)	
            g << "-1 ";	
        else	
            g << d[i] << " ";
	
    return 0;	
}