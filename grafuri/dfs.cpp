// https://infoarena.ro/problema/dfs

#include <fstream>	
#include <vector>	
#define NMAX 100005	
 	
using namespace std;
 	
ifstream f("dfs.in");	
ofstream g("dfs.out");	
 	
int i, n, m, x, y, ans = 0;	
bool used[NMAX];	
vector < int > v[NMAX];	
 	
void DFS(int node)	
{	
    used[node] = 1;	
 
	for (auto & it : v[node])	
        if (!used[it])	
            DFS(it);	
}	
 	
int main()	
{	
    f >> n >> m;	
 	
    for (i = 1; i <= m; ++ i)	
    {	
        f >> x >> y;	
        v[x].push_back(y);	
        v[y].push_back(x);	
    }	
 	
    for (i = 1; i <= n; ++ i)	
        if (!used[i])	
    {	
        ans ++;	
        DFS(i);	
    }
 	
    g << ans << '\n';	
    return 0;	
}