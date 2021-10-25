// https://www.infoarena.ro/problema/dragoni

#include <fstream>
	
#include <algorithm>
	
#include <vector>
	
#include <queue>
	
#define NMAX 805
	
#define pb push_back
	
#define mp make_pair
	
#define inf 2000000000
	
 
	
using namespace std;
	
 
	
ifstream f("dragoni.in");
	
ofstream g("dragoni.out");
	
 
	
int i, n, m, type, dr[NMAX], d[NMAX], x, y, z, mat[NMAX][NMAX], j;
	
bool visited[NMAX][NMAX], vis[NMAX];
	
vector < pair < int, int > > v[NMAX];
	
 
	
void read()
	
{
	
    f >> type >> n >> m;
	
 
	
    for (i = 1; i <= n; ++ i)
	
        f >> dr[i];
	
 
	
    for (i = 1; i <= m; ++ i)
	
    {
	
        f >> x >> y >> z;
	
        v[x].pb(mp(z, y));
	
        v[y].pb(mp(z, x));
	
    }
	
}
	
 
	
 
	
void solve2()
	
{
	
    queue < pair < int, int > > q;
	
    for (i = 1; i <= n; ++ i)
	
        sort(v[i].begin(), v[i].end());
	
 
	
    for (i = 1; i <= n; ++ i)
	
        for (j = 1; j <= n; ++ j)
	
        mat[i][j] = inf;
	
 
	
    q.push(mp(1, 1));
	
    visited[1][1] = 1;
	
    mat[1][1] = 0;
	
 
	
    int ans = inf;
	
 
	
    while (!q.empty())
	
    {
	
        pair < int, int > curr = q.front();
	
        q.pop();
	
 
	
        visited[curr.first][curr.second] = 0;
	
        int aux = mat[curr.first][curr.second];
	
 
	
        if (dr[curr.first] > dr[curr.second])
	
            curr.second = curr.first;
	
 
	
        for (auto &it : v[curr.first])
	
            if (dr[curr.second] < it.first)
	
                break;
	
        else
	
        if (aux + it.first < ans && aux + it.first < mat[it.second][curr.second])
	
        {
	
            if (it.second == n)
	
            {
	
                ans = aux + it.first;
	
                continue;
	
            }
	
 
	
            mat[it.second][curr.second] = aux + it.first;
	
 
	
            if (!visited[it.second][curr.second])
	
            {
	
                q.push(mp(it.second, curr.second));
	
                visited[it.second][curr.second] = 1;
	
            }
	
        }
	
    }
	
    g << ans << '\n';
	
}
	
 
	
int main()
	
{
	
    read();
	
 
	
    if (type == 1)
	
    {
	
        int ans = dr[1];
	
        queue < int > q;
	
 
	
        q.push(1);
	
 
	
        while (!q.empty())
	
        {
	
            int curr = q.front();
	
            q.pop();
	
 
	
            for (auto &it : v[curr])
	
                if (!vis[it.second] && it.first <= dr[1])
	
            {
	
                vis[it.second] = 1;
	
                ans = max(ans, dr[it.second]);
	
                q.push(it.second);
	
            }
	
        }
	
 
	
        g << ans << '\n';
	
    }
	
    else
	
        solve2();
	
    return 0;
	
}