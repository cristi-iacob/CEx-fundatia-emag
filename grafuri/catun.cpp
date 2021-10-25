// https://www.infoarena.ro/problema/catun

#include <fstream>
	
#include <algorithm>
	
#include <vector>
	
#include <queue>
	
#define NMAX 36005
	
#define inf (1 << 30)
	
 
	
using namespace std;
	
 
	
ifstream f("catun.in");
	
ofstream g("catun.out");
	
 
	
int i, n, m, a, b, c, k, d[NMAX], boss[NMAX], start[NMAX];
	
vector < pair < int, int > > v[NMAX];
	
 
	
struct comp
	
{
	
    bool operator () (pair < int, int > &a, pair < int, int > &b)
	
    {
	
        return a.second > b.second;
	
    }
	
};
	
 
	
priority_queue < pair <int, int >, vector < pair < int, int > >, comp > pq;
	
 
	
void read()
	
{
	
    f >> n >> m >> k;
	
 
	
    for (int i = 1; i <= k; ++ i)
	
        f >> start[i];
	
 
	
    for (int i = 1; i <= m; ++ i)
	
    {
	
        f >> a >> b >> c;
	
 
	
        v[a].push_back(make_pair(b, c));
	
        v[b].push_back(make_pair(a, c));
	
    }
	
}
	
 
	
void initialize()
	
{
	
    for (int i = 1; i <= n; ++ i)
	
    {
	
        d[i] = inf;
	
        boss[i] = inf;
	
    }
	
 
	
    for (int i = 1; i <= k; ++ i)
	
    {
	
        boss[start[i]] = start[i];
	
        d[start[i]] = 0;
	
    }
	
}
	
 
	
void dijkstra(int node)
	
{
	
    pq.push(make_pair(node, 0));
	
 
	
    while (!pq.empty())
	
    {
	
        int current = pq.top().first;
	
        pq.pop();
	
 
	
        for (auto &it : v[current])
	
        if (d[it.first] > d[current] + it.second || (d[it.first] == d[current] + it.second && boss[current] < boss[it.first]))
	
        {
	
            d[it.first] = d[current] + it.second;
	
            pq.push(make_pair(it.first, d[it.first]));
	
            boss[it.first] = boss[current];
	
        }
	
    }
	
}
	
 
	
 
	
int main()
	
{
	
    read();
	
    initialize();
	
 
	
    for (i = 1; i <= k; ++ i)
	
        dijkstra(start[i]);
	
 
	
    for (i = 1; i <= k; ++ i)
	
        boss[start[i]] = 0;
	
 
	
    for (i = 1; i <= n; ++ i)
	
        if (boss[i] == inf)
	
            boss[i] = 0;
	
 
	
    for (i = 1; i <= n; ++ i)
	
        g << boss[i] << " ";
	
    return 0;
	
}