// https://infoarena.ro/problema/biconex

#include <fstream>
	
#include <stack>
	
#include <vector>
	
#include <algorithm>
	
#define NMAX 100005
	
 
	
using namespace std;
	
 
	
ifstream f("biconex.in");
	
ofstream g("biconex.out");
	
 
	
int i, n, m, x, y, low[NMAX], lvl[NMAX], cnt = 0;
	
vector < int > v[NMAX], ans[NMAX];
	
bool visited[NMAX];
	
stack < pair < int, int > > st;
	
 
	
void DFS(int node, int father)
	
{
	
    visited[node] = 1;
	
    lvl[node] = lvl[father] + 1;
	
    low[node] = lvl[node];
	
 
	
    for (vector < int > :: iterator it = v[node].begin(); it != v[node].end(); ++ it)
	
    {
	
        if (visited[*it])
	
            low[node] = min(low[node], lvl[*it]);
	
        else
	
        {
	
            st.push({*it, node});
	
            DFS(*it, node);
	
            low[node] = min(low[node], low[*it]);
	
 
	
            if (low[*it] >= lvl[node])
	
            {
	
                cnt ++;
	
 
	
                while (st.top().second != node)
	
                {
	
                    ans[cnt].push_back(st.top().first);
	
                    st.pop();
	
                }
	
 
	
                ans[cnt].push_back(node);
	
                ans[cnt].push_back(*it);
	
                st.pop();
	
            }
	
        }
	
    }
	
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
	
 
	
    DFS(1, 0);
	
 
	
    g << cnt << '\n';
	
 
	
    for (i = 1; i <= cnt; ++ i)
	
    {
	
        for (int j = 0; j < ans[i].size(); ++ j)
	
            g << ans[i][j] << " ";
	
        g << '\n';
	
    }
	
    return 0;
	
}