// https://www.infoarena.ro/problema/lca

#include <fstream>
	
#include <vector>
	
#include <cmath>
	
#define NMAX 100005
	
#define LMAX 20
	
 
	
using namespace std;
	
 
	
ifstream f("lca.in");
	
ofstream g("lca.out");
	
 
	
int i, n, m, x, euler[4 * NMAX], rmq[LMAX][4 * NMAX], cnt = 0, lvl[4 * NMAX], pos[NMAX], j;
	
bool visited[NMAX];
	
 
	
vector < int > v[NMAX];
	
 
	
void DFS(int node, int level)
	
{
	
    visited[node] = 1;
	
    euler[++ cnt] = node;
	
    lvl[cnt] = level;
	
 
	
    if (pos[node] == 0)
	
        pos[node] = cnt;
	
 
	
    for (vector < int > :: iterator it = v[node].begin(); it != v[node].end(); ++ it)
	
        if (!visited[*it])
	
        {
	
            DFS(*it, level + 1);
	
            euler[++ cnt] = node;
	
            lvl[cnt] = level;
	
        }
	
}
	
 
	
int main()
	
{
	
    f >> n >> m;
	
 
	
    for (i = 2; i <= n; ++ i)
	
    {
	
        f >> x;
	
        v[i].push_back(x);
	
        v[x].push_back(i);
	
    }
	
 
	
    DFS(1, 1);
	
 
	
  /*  for (i = 1; i <= cnt; ++ i)
	
        g << euler[i] << " ";
	
    g << '\n';
	
{1}
	
    for (i = 1; i <= cnt; ++ i)
	
        g << lvl[i] << " ";*/
	
 
	
    for (i = 1; i <= cnt; ++ i)
	
        rmq[0][i] = i;
	
 
	
    for (j = 1; (1 << j) <= cnt; ++ j)
	
        for (i = 1; i + (1 << j) - 1 <= cnt; ++ i)
	
            if (lvl[rmq[j - 1][i]] < lvl[rmq[j - 1][i + (1 << (j - 1))]])
	
                rmq[j][i] = rmq[j - 1][i];
	
            else
	
                rmq[j][i] = rmq[j - 1][i + (1 << (j - 1))];
	
 
	
    for (i = 1; i <= m; ++ i)
	
    {
	
        int st, dr;
	
 
	
        f >> st >> dr;
	
 
	
        st = pos[st];
	
        dr = pos[dr];
	
 
	
        if (st > dr)
	
            swap(st, dr);
	
 
	
        int l = log2(dr - st + 1);
	
 
	
        if (lvl[rmq[l][st]] < lvl[rmq[l][dr - (1 << l) + 1]])
	
            g << euler[rmq[l][st]] << '\n';
	
        else
	
            g << euler[rmq[l][dr - (1 << l) + 1]] << '\n';
	
    }
	
 
	
    return 0;
	
}