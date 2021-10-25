// https://infoarena.ro/problema/sortaret

#include <fstream>
	
#define NMAX 50005
	
#include <vector>
	
 
	
using namespace std;
	
 
	
ifstream f("sortaret.in");
	
ofstream g("sortaret.out");
	
 
	
int i, n, m, x, y;
	
vector < int > v[NMAX];
	
bool visited[NMAX];
	
 
	
void DFS(int node)
	
{
	
    visited[node] = 1;
	
 
	
    for (auto &it : v[node])
	
        if (!visited[it])
	
            DFS(it);
	
 
	
    g << node << " ";
	
}
	
 
	
int main()
	
{
	
    f >> n >> m;
	
 
	
    for (i = 1; i <= m; ++ i)
	
    {
	
        f >> x >> y;
	
        v[y].push_back(x);
	
    }
	
 
	
    for (i = 1; i <= n; ++ i)
	
        if (!visited[i])
	
            DFS(i);
	
    return 0;
	
}