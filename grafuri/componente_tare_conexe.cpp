// https://infoarena.ro/problema/ctc

#include <fstream>
	
#include <vector>
	
#define NMAX 100005
	
 
	
using namespace std;
	
 
	
ifstream f("ctc.in");
	
ofstream g("ctc.out");
	
 
	
int i, n, m, x, y, cnt = 0, start[NMAX], anscnt;
	
bool visited[NMAX];
	
 
	
vector < int > v[NMAX], ans[NMAX], vt[NMAX];
	
 
	
void DFS1(int node)
	
{
	
    visited[node] = 1;
	
 
	
    for (vector < int > :: iterator it = v[node].begin(); it != v[node].end(); ++ it)
	
        if (!visited[*it])
	
            DFS1(*it);
	
 
	
    start[++ cnt] = node;
	
}
	
 
	
void DFS2(int node)
	
{
	
    visited[node] = 0;
	
    ans[anscnt].push_back(node);
	
 
	
    for (vector < int > :: iterator it = vt[node].begin(); it != vt[node].end(); ++ it)
	
        if (visited[*it])
	
            DFS2(*it);
	
}
	
 
	
int main()
	
{
	
    f >> n >> m;
	
 
	
    for (i = 1; i <= m; ++ i)
	
    {
	
        f >> x >> y;
	
        v[x].push_back(y);
	
        vt[y].push_back(x);
	
    }
	
 
	
    for (i = 1; i <= n; ++ i)
	
        if (!visited[i])
	
            DFS1(i);
	
 
	
    for (i = cnt; i >= 1; -- i)
	
        if (visited[start[i]])
	
        {
	
            anscnt ++;
	
            DFS2(start[i]);
	
        }
	
 
	
    g << anscnt << '\n';
	
 
	
    for (i = 1; i <= anscnt; ++ i)
	
    {
	
        for (vector < int > :: iterator it = ans[i].begin(); it != ans[i].end(); ++ it)
	
            g << *it << " ";
	
        g << '\n';
	
    }
	
    return 0;
	
}